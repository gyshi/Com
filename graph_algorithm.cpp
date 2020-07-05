//
// Created by Jiyang Gong on 2020-04-08.
//

#include "graph_algorithm.h"
#include <stack>
#include <omp.h>
#include <sys/time.h>

bool Query::FindMatch(BiGraph &bigraph) {
  if (bigraph.MaxMatch() == bigraph.leftn_) return true;
  return false;
}
bool Query::Check(const Graph &graph) {

  if (this->search_core_.size() < this->query_sum_) return false;

  int search_core_k = 1e9;
  for (auto x : this->search_core_) {
    int cnt = 0;
    for (auto edge : graph.edge_[x]) {
      int y = edge;
      if (this->choose_[y]) ++cnt;
    }
    search_core_k = min(search_core_k, cnt);
  }
  if (search_core_k < find_core_k_) return false;
  if (search_core_k == find_core_k_ && this->search_core_.size() >= find_core_.size()) return false;


  vector<int> attribute_sum(graph.max_attribute_ + 1, 0);
  for (auto x : this->search_core_) {
    for (auto attribute : graph.vertex_[x].attribute_) {
      attribute_sum[attribute]++;
    }
  }
  for (auto query : this->queries) {
    int attribute, number;
    tie(attribute, number) = query;
    if( (attribute_sum[attribute] < number)) return false;
  }

  int leftn = 0;
  for (int i = 0; i < queries.size(); ++i)
    leftn += get<1>(queries[i]);
  BiGraph bigraph(leftn, this->search_core_.size());

  vector<vector<int>> assign(graph.max_attribute_ + 1, vector<int>());//[1,max_attribute_]

  for (int j = 0; j < this->search_core_.size(); j++) {
    for(auto attribute : graph.vertex_[this->search_core_[j]].attribute_)
      assign[attribute].push_back(j);
  }

  int n = 0;
  for (int i = 0; i < queries.size(); ++i) {
    int attribute, number;
    tie(attribute, number) = queries[i];
    for (int i = 1; i <= number; ++i) {
      for (auto x : assign[attribute]) {
        bigraph.edge_[n].push_back(x);
      }
      ++n;
    }
  }

  if (this->FindMatch(bigraph)) {
    find_core_k_ = search_core_k;
  
    this->find_core_.clear();
    printf("\n, %s, %d, \n", "-----------find core k :",find_core_k_);
    for (auto x :  this->search_core_) {
     printf("%s, %d"," ", this->id_[x] + 1);
     this->find_core_.push_back(this->id_[x]);
}
    printf("\n,%s, \n", "________find k  core end");
    return true;
  } else {
    return false;
  }

  return true;

}

//Query::Query(int n, string input_str) {
//  this->choose_.resize(n);
//  find_core_k_ = -1;
//
//#ifdef Test
//  cost_ = 0;
//#endif
//  freopen(("./cmake-build-debug/" + input_str).c_str(), "r", stdin);
////  freopen("/Users/oumitsumomo/Documents/论文/代码/Community/query.in", "r", stdin);
//  int nq;
//  query_sum_ = 0;
//  read(query_maxsize_);read(nq);
//  for (int i = 1; i <= nq; ++i) {
//    int attribute, number;
//    read(attribute); read(number);
//    this->queries.push_back(make_tuple(attribute, number));
//    query_sum_ += number;
//  }
//}

Query::Query(int n, vector<int> line) {
    this->choose_.resize(n);
    find_core_k_ = -1;


#ifdef Test
    cost_ = 0;
#endif
//    freopen(("./cmake-build-debug/" + input_str).c_str(), "r", stdin);
//  freopen("/Users/oumitsumomo/Documents/论文/代码/Community/query.in", "r", stdin);
    int nq;
    query_sum_ = 0;
    query_maxsize_ = line[0];nq = line[1];
    for (int i = 2; i <= 2*nq; i+=2) {
        int attribute = line[i];
        int number = line[i+1];
        this->queries.push_back(make_tuple(attribute, number));
        query_sum_ += number;
    //   cerr << "attribues: "<< attribute << endl;     
    }
    this->theory_k_min = 1;
    this->theory_k_max = query_sum_ - 1;
    this->theory_size_min = query_sum_; 
    this->theory_size_max = query_maxsize_;
}

int Query::ExpectedKCore(const Graph &graph, int limit) {
  if (this->search_core_.size() == 0) return -1;
  int expected_core_k  = 1e9;
  for (auto x : this->search_core_) {
    int cnt1 = 0, cnt2 = 0;
    for (auto y : graph.edge_[x]) {
      if (this->choose_[y]) ++cnt1;
      else if(y > limit) ++cnt2;
    }
  
    expected_core_k = min(expected_core_k, cnt1 + min(cnt2, this->query_maxsize_ - (int)this->search_core_.size()));
//    printf("%s, %d,%d,%d\n", "******expected***:core_k, cnt1, cnt2, sub:", expected_core_k, cnt1, cnt2, this->query_maxsize_ - (int)this->search_core_.size());
  }
  return expected_core_k;
}

//邻居节点候选集包含查询中的属性
//vector<int> Query::NeighborID(Graph graph, int u){
//
//    vector <int> NeiborID;
//    for(auto edge_u:graph.edge_[u]){
//        int v = edge_u;
//        for (auto attribute : graph.vertex_[v].attribute_) {
//            for (auto query : this->queries) {
//                if(attribute == std::get<0>(query)) {
//                    NeiborID.push_back(v);
//                    break;
//                }
//            }
//        }
//    }
//
//    return NeiborID;
//}


void Query::Search(const Graph &graph, int x) {

#ifdef Test
  ++this->cost_;

#endif

      if (x == graph.n_) return;

      if (this->ExpectedKCore(graph, x - 1) < this->find_core_k_) {
          return;
      }

      // clock_t start, finish; //定义开始，结束变量
        double start, finish;
       double duration = 0.0;
      //start = clock();//初始化
       start = omp_get_wtime();
         
      this->Check(graph);
          //return; ->want to maxmize core_k, cant'return

      // finish = clock();//初始化结束时间
    	finish = omp_get_wtime();
      //duration = (double) (finish - start) / CLOCKS_PER_SEC;//转换浮点型
      duration = finish - start;
      this->check_time += duration; //统计check函数

      if (this->search_core_.size() + 1 > this->query_maxsize_) {
          return;
      }
      int cnt1 = 0, cnt2 = 0, connected = 0;

      for (int i = 0; i < graph.edge_[x].size(); ++i) {
          if (this->choose_[graph.edge_[x][i]]) cnt1++;
          else if (graph.edge_[x][i] > x) cnt2++;
          if (this->choose_[graph.edge_[x][i]]) connected = 1;
      }

     int cnt = cnt1 + min(cnt2, this->query_maxsize_ - (int) this->search_core_.size() - 1);
      if (connected && !(cnt < this->find_core_k_ ||
                         (cnt == this->find_core_k_ && search_core_.size() >= this->find_core_.size()))) {
          this->choose_[x] = 1;
          this->search_core_.push_back(x);
          Search(graph, x + 1);
          this->search_core_.pop_back();
          this->choose_[x] = 0;
      }

      Search(graph, x + 1);

}

void Query::Output() {

    printf("%s %d\n", "Find_Core_K:", this->find_core_k_);
  printf("Find_Core_Vertices:");
  int size = 0;
  for (auto x : this->find_core_) {
        printf("%d",x+1);
        printf(" ");
      size += 1;
  }
    printf("\n");
    printf("%s %d\n","Find_Core_Size:",size);
    printf("%s %d\n", "Search call times:", this->cost_);
   
}

Graph  Query:: ReidGraph(const Graph &graph, vector<int> & id , int st) {
  queue<int> q;
  q.push(st);
  vector<int> vis(graph.n_, 0);
  int id_now = 0;
  id[st] = id_now;
  vis[st] = 1;
  //cerr<<"Reid"<<endl;
  //clock_t start1,finish1; 
  //start1 = clock();
  int query_num = 0;   
  double start1, finish1;
  start1 = omp_get_wtime();
  int max_size = 0;
  map<int,int> Cond_Attr;
  for (auto query :this->queries) {
    Cond_Attr[std::get<0>(query)] = std::get<1>(query);
    query_num++;
  }
  bool attr_flag = false;
  
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    
  int attr_count = 0;
    for (auto attr : graph.vertex_[x].attribute_) {
      for (auto query : Cond_Attr) {
         if (attr == query.first) {
           query.second--;
         }
      }
    }
  for (auto x : Cond_Attr) {
    if (x.second <= 0) attr_count++;
  }
  if (query_num == attr_count) {
    attr_flag = true;
  }

    if (max_size >= this->theory_size_max) break;

    max_size += 1;
    for (auto y : graph.edge_[x]) {
      if (vis[y]) continue;
      if (y < st) continue;
      bool has_attr=false;
      for (auto y1 : graph.edge_[y]){
         for (auto attr_val: graph.vertex_[y1].attribute_) {
          for (auto query: this->queries) {
           if (attr_val == std::get<0>(query)) has_attr=true;
         }
     }   
   //   if (y < st) continue;
   }
      vis[y] = 1;
      if (has_attr) {
      has_query[y] = 1;
      q.push(y);
      id[y] = ++id_now;
   }
    }

    if (attr_flag) break;
  }
  //finish1 = clock();
  finish1 = omp_get_wtime();
  double duration1 = finish1 - start1;
  // double duration1 = (double)(finish1 - start1) / CLOCKS_PER_SEC; 
// printf("%s %lf %s\n","Reid__1:", duration1,"seconds");
  //start1 = clock();
    // cerr<<"Begin reid_graph"<<endl;
 // assert(id_now + st == graph.n_ - 1); //从st出发走不到所有点的，在<st点删除情况下
 Graph reid_graph(id_now + 1);
  // cerr<<"end reid_graph"<<endl;
  reid_graph.max_attribute_ = graph.max_attribute_;
  for (int i = 0; i < graph.n_; ++i) {
    if (id[i] == -1) continue;
    for (auto y : graph.vertex_[i].attribute_)
      reid_graph.vertex_[id[i]].attribute_.push_back(y);
    for (auto y : graph.edge_[i]) {
      if (id[y] == -1) continue;
      reid_graph.edge_[id[i]].push_back(id[y]);
    }
  }
  //finish1 = clock();
 // duration1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
// printf("%s %lf %s\n","Reid__2:", duration1,"seconds");

  // cerr<<"return reid_graph"<<endl;
  return reid_graph;

}


Graph  Query:: OptGraph(const Graph &graph, vector<int> & id, int st) {
  queue<int> q;
  q.push(st);
  vector<int> vis(graph.n_, 0);
  int id_now = 0;
  id[st] = id_now;
  vis[st] = 1;
  //cerr<<"Reid"<<endl;
  //clock_t start1,finish1;
  //start1 = clock();
 // double start1, finish1;
 // start1 = omp_get_wtime();
  
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto y : graph.edge_[x]) {
      if (vis[y]) continue;
      if (y < st) continue;
      vis[y] = 1;
      q.push(y);
      id[y] = ++id_now;
    }
  }

  printf("%s,%d\n","################",id_now);
  //finish1 = clock();
 // finish1 = omp_get_wtime();
 // double duration1 = finish1 - start1;
  // double duration1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
// printf("%s %lf %s\n","Reid__1:", duration1,"seconds");
  //start1 = clock();
    // cerr<<"Begin reid_graph"<<endl;
 // assert(id_now + st == graph.n_ - 1); //从st出发走不到所有点的，在<st点删除情况下
 Graph reid_graph(graph.n_);
  // cerr<<"end reid_graph"<<endl;
  reid_graph.max_attribute_ = graph.max_attribute_;
  for (int i = 0; i < graph.n_; ++i) {
    if (id[i] == -1) continue;
    for (auto y : graph.vertex_[i].attribute_)
      reid_graph.vertex_[id[i]].attribute_.push_back(y);
    for (auto y : graph.edge_[i]) {
      if (id[y] == -1) continue;
      reid_graph.edge_[id[i]].push_back(id[y]);
    }
  }
  //finish1 = clock();
 // duration1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
// printf("%s %lf %s\n","Reid__2:", duration1,"seconds");

  // cerr<<"return reid_graph"<<endl;
  return reid_graph;

}


//起始候选节点包含查询中的属性
bool query_cmp(pair<vector<int>, int>&a, pair<vector<int>, int>&b)
{
	return a.second > b.second;
}

bool attr_cmp(pair<int, int>&a, pair<int, int>&b)
{
	return a.second > b.second;
}
void Query::CountAttributes(const Graph &graph){
    int count = 0;
    map<int,int> dif_querynumber;
    map<vector<int>,int> dif_query;
    vector<int> queryattribute;
    dif_query.insert(pair<vector<int>,int>(queryattribute,0));
    dif_querynumber[0] = 0;
    for (auto query : this->queries)this->querymap[std::get<0>(query)] = 0;

    for (int i = 0;i < graph.n_; ++i){
        int flag = 0;
        for (auto attribute : graph.vertex_[i].attribute_) {
            for (auto query : this->queries) {
                if(attribute == std::get<0>(query)) {
                    this->querymap[std::get<0>(query)] += 1;
                    flag += 1;
                    if(flag == 1)count += 1;
                    queryattribute.push_back(attribute);
                }
            }
        }
        dif_querynumber[flag] += 1;
        dif_query[queryattribute] += 1;
        queryattribute.clear();

    }

    printf("%s %d\n","Vertices number of containing query attribute:",count);
    printf("%s\n", "Vertices number of containing n attribute:");

    for (auto& x: dif_querynumber) {
            printf("%d %s %d\n", x.first, ":", x.second);
        }
    printf("%s\n", "Vertices number of concrete query attributes:");
    for (auto& i: dif_query){
        if (i.first.size() != 0 ) {
            printf("%s", "{");
        for(int k =0 ;k < i.first.size(); k++) {
            printf("%d",i.first[k]);
            this->select_attr[i.first[k]] += i.second;
            if (k != i.first.size()-1)
                printf("%s",",");
        }
            printf("%s", "}: ");
            printf("%d\n",i.second);

        }
    }

   printf("%s\n", "Attributes  number :");
    for (auto& i: this->select_attr){
            printf("%s", "{");
            printf("%d",i.first);
             printf("%s",",");
            printf("%s", "}: ");
            printf("%d\n",i.second);

        }
    vector<pair<int, int> > select_query;
    for(map<int, int>::iterator it = this->select_attr.begin(); it != this->select_attr.end(); it++) {
        select_query.push_back(pair<int, int>(it->first, it->second));

    }

    sort(select_query.begin(), select_query.end(), attr_cmp);
    


    vector<pair<vector<int>, int> > sort_query;
    for(map<vector<int>, int>::iterator it = dif_query.begin(); it != dif_query.end(); it++) {
        sort_query.push_back(pair<vector<int>, int>(it->first, it->second));
	
    }
 
    sort(sort_query.begin(), sort_query.end(), query_cmp);

    printf("%s\n", "Sort Vertices number of concrete query attributes:");
    for (auto& i: sort_query){
        if (i.first.size() != 0 ) {
            printf("%s", "{");

        for(int k =0 ;k < i.first.size(); k++) {
            printf("%d",i.first[k]);
            if (k != i.first.size()-1)
                printf("%s",",");
        }
            printf("%s", "}: ");
            printf("%d\n",i.second);

        }
    }


}

vector<int> Query::StartID(Graph graph){

    vector <int> stID;

    for (int i = 0;i < graph.n_; ++i){
    //  if (graph.edge_[i].size() < this->theory_k_min) continue;
        int flag = 0;
        for (auto attribute : graph.vertex_[i].attribute_) {
            for (auto query : this->queries) {
                if(attribute == std::get<0>(query)) {
                    stID.push_back(i);
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)break;
        }
    }

    return stID;

}


Graph Query::NewGraph(const Graph &graph){

    vector <int> stID;
    map<int, int>new_map_old;  // old -> new
    int new_id = 0;

    for (int i = 0;i < graph.n_; ++i){
    //  if (graph.edge_[i].size() < this->theory_k_min) continue;
        int flag = 0;
        for (auto attribute : graph.vertex_[i].attribute_) {
            for (auto query : this->queries) {
                if(attribute == std::get<0>(query)) {
                    stID.push_back(i);
                    new_map_old[i] = new_id;
                    ++new_id;
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)break;
        }
    }
  int New_n = stID.size();
  Graph new_graph(New_n);
  new_graph.vertex_ = vector<Vertex> (New_n);
  new_graph.edge_ = vector<vector<int> >(New_n);
  new_graph.max_attribute_ = graph.max_attribute_;

  for (auto idex : stID) {
      for (auto y : graph.vertex_[idex].attribute_) {
         for (auto query : this->queries) 
             if (y ==  std::get<0>(query)) 
      		new_graph.vertex_[new_map_old[idex]].attribute_.push_back(y);
       } 
      for (auto y : graph.edge_[idex]) {
           for (auto next_idex: stID) {
                if (y == next_idex) 
                    new_graph.edge_[new_map_old[idex]].push_back(new_map_old[y]);
           }
       }    
  }
// test new_graph 
//   printf("test-------new_graph___________\n");
//  for (auto idex : stID) {
//     
//     for (auto x: new_graph.edge_[new_map_old[idex]])
//        printf("%s,%d, %d,%d ,%s\n", "new_graph: ",idex, new_map_old[idex], x, " ");
//    
//}
//printf(" %s\n","-------------------------------end!!!!!!!!!!!!");
  return new_graph;

}

bool Query::ConditionAttr(Graph &graph) {
  map<int,int> Cond_Attr;
  int sum_attr = 0;
  int app_numb = 0;  
  for (auto query :this->queries) {
    Cond_Attr[std::get<0>(query)] = std::get<1>(query);
  }
  for (int i = 0; i < graph.n_; ++i) {
    for (auto y : graph.vertex_[i].attribute_) 
       for (auto query : Cond_Attr) {
         int count = 0;
          if (query.first == y) {
             sum_attr++;
            if (count >= 1 ) {
              app_numb++;
            } else {
              count++;
            query.second--;
            }
          }
       }
  }
  if (sum_attr - app_numb < this->theory_size_min ) return false;
  for (auto x : Cond_Attr) {
    if (x.second > 0) return false;
   
  }
   return true;

}

void Query::Start(const Graph &graph) {

    this->check_time = 0.0;
    this->search_time = 0.0;
    this->reid_time = 0.0;
    vector <int> stID  = this->StartID(graph);
    int i;
    for (int i = 0; i < graph.n_; ++i)
    has_query[i] = -1;  
  // omp_set_num_threads(32);

// #pragma omp parallel default(shared) private(i)
//{

// #pragma omp for schedule(static) nowait
  for (i = 0; i < stID.size(); ++i) {

     // clock_t start1,finish1; //定义开始，结束变量
      // start1 = clock();//初始化开始时间
      if (has_query[i] == 1) continue;
       double  start1,finish1; 
        start1 = omp_get_wtime();
	vector<int> id(graph.n_, -1);
      // cerr<<"Start"<<endl;
      Graph reid_graph = this->ReidGraph(graph, id, stID[i]);
       if (ConditionAttr(reid_graph)) continue;
      // cerr<<"End ReId";
     this->id_.resize(graph.n_);
   //  #pragma omp critical 
    if(true) {
    for (int x = 0; x < id.size(); ++x) {
      if (id[x] == -1) continue;
      this->id_[id[x]] = x;
    }
      finish1 = omp_get_wtime();//初始化结束时间
	double duration1 = finish1 - start1;
     this->reid_time += duration1;


       double  start2,finish2; 
        start2 = omp_get_wtime();
    if ((int)reid_graph.edge_[0].size() >= find_core_k_) { //找到的k-core期望不小于原先的
      this->search_core_.push_back(0);
      this->choose_[0] = 1;
     // printf("%s, %d", "+++++++++++++++++++++++++++++++++++++++++",i);
      // cerr<<"begin search"<<endl;
      this->Search(reid_graph, 1);
      // cerr<<"end search" <<endl;
      this->search_core_.pop_back();
      this->choose_[0] = 0;
     }
     finish2 = omp_get_wtime();//初始化结束时间
	double duration2 = finish2 - start2;
      this->search_time += duration2;
  }
}

// }
    printf("%s %lf %s\n","ReidTime:", this->reid_time,"seconds");
    printf("%s %lf %s\n","SearchTime:", this->search_time,"seconds");
    printf("%s %lf %s\n","CheckTime:", this->check_time,"seconds");
//}
}

