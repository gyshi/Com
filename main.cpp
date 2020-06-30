
#include "include.h"
#include "core.h"
#include "truss.h"
#include "ks_core.h"
#include "graph.h"
#include "file_manage.h"
#include "ego_community.h"
#include "clique.h"
#include "tree.h"
#include "graph_algorithm.h"
#include <omp.h>

#define CHUNKSIZE 100

//void TestDataset(Graph &graph){
//
//    clock_t start,finish; //定义开始，结束变量
//    double duration;
//    // Get core'K
//    start = clock();//初始化
//    CoreDelLine core_del_line = FindCore(graph);
//    cout << "Core'K="<<core_del_line[core_del_line.size()-1].k_<<endl;
//    sort(core_del_line[core_del_line.size()-1].del_vertex_.begin(), core_del_line[core_del_line.size()-1].del_vertex_.end());
//    for(auto v: core_del_line[core_del_line.size()-1].del_vertex_)cout<<v<<" ";cout<<endl;
//    finish = clock();//初始化结束时间
//    duration = (double)(finish - start) / CLOCKS_PER_SEC;//转换浮点型
//    printf( "TestCore %lf seconds\n", duration );
//
////Get truss'K
//    start = clock();//初始化
//    Truss_sup truss = FindTruss(graph);
//    int max_truss = 0;
//    for (int i = 0; i < graph.m_; i++) max_truss = max(max_truss, truss[i].sup_);
//    cout << "Truss_sup'K="<<max_truss << endl;
//    finish = clock();//初始化结束时间
//    duration = (double)(finish - start) / CLOCKS_PER_SEC;//转换浮点型
//    printf( "TestTruss %lf seconds\n", duration );
//
////Get the number of triangle
//    start = clock();//初始化
//    Truss_sup sup_edge = ComputerSup(graph);
//    int sum_truss = 0;
//    for(int i = 0; i < graph.m_; i++) sum_truss += sup_edge[i].sup_;
//    cout<<"the number of triangles="<< sum_truss/3 <<endl;
//    finish = clock();//初始化结束时间
//    duration = (double)(finish - start) / CLOCKS_PER_SEC;//转换浮点型
//    printf( "Testtriangle %lf seconds\n", duration );
//
//
////Get ego_core'K
//    start = clock();//初始化
//    EgoCoreDelLine  ego_core_del_line = EgoCore(graph);
//    cout << "Ego_Core'K="<<ego_core_del_line[ego_core_del_line.size()-1].k_<<endl;
//    sort(ego_core_del_line[ego_core_del_line.size()-1].del_vertex_.begin(),ego_core_del_line[ego_core_del_line.size()-1].del_vertex_.end());
//    for(auto v: ego_core_del_line[ego_core_del_line.size()-1].del_vertex_)cout<<v<<" ";cout<<endl;
//    finish = clock();//初始化结束时间
//    duration = (double)(finish - start) / CLOCKS_PER_SEC;//转换浮点型
//    printf( "TestEgo_Core %lf seconds\n", duration );
//
//    //Get ego_core_fast'K
////    start = clock();//初始化
////    EgoCoreDelLine ego_core_del_line_fast = EgoCoreFast(graph);
////    cout << "Ego_Core_Fast'K="<<ego_core_del_line_fast[ego_core_del_line_fast.size()-1].k_<<endl;
////    finish = clock();//初始化结束时间
////    duration = (double)(finish - start) / CLOCKS_PER_SEC;//转换浮点型
////    printf( "TestEgo_Core %lf seconds\n", duration );
////Get ego_core_baseline'K
////    EgoCoreDelLine ego_core_del_line_bl = EgoCoreBaseline(graph);
////    cout << "Ego_Core_baseline'K="<<ego_core_del_line_bl[ego_core_del_line_bl.size()-1].k_<<endl;
////    sort(ego_core_del_line_bl[ego_core_del_line_bl.size()-1].del_vertex_.begin(),ego_core_del_line_bl[ego_core_del_line_bl.size()-1].del_vertex_.end());
////    for(auto v: ego_core_del_line_bl[ego_core_del_line_bl.size()-1].del_vertex_)cout<<v<<" ";cout<<endl;
//
//
//}
//void Print(EgoCoreDelLine ego_core_del_line, string str){
//    for(auto del_line:ego_core_del_line) {
//        LOG2(str, del_line.k_);
//        for (auto v:del_line.del_vertex_) {
//            LOG(v + 1)
//        }
//    }
//}
//int  Compapre(EgoCoreDelLine &ego_core_del_line,EgoCoreDelLine &ego_core_del_line_bl){
//    if(ego_core_del_line.size() != ego_core_del_line_bl.size()) return 0;
//    for(int i = 0; i < ego_core_del_line.size();i++){
//        if(ego_core_del_line[i].k_ != ego_core_del_line_bl[i].k_) return 0;
//        if(ego_core_del_line[i].del_vertex_.size() != ego_core_del_line_bl[i].del_vertex_.size()) return 0;
//        for(int j = 0; j < ego_core_del_line[i].del_vertex_.size(); j++)
//            if(ego_core_del_line[i].del_vertex_[j] != ego_core_del_line_bl[i].del_vertex_[j]) return 0;
//    }
//    return 1;
//}
//void TestEgo(){
//    Graph graph;
//    EgoCoreDelLine ego_core_del_line_bl,ego_core_del_line;
//    do {
//        graph.ClearGraph();
//        graph.InputGraph();
//
//        ego_core_del_line_bl = EgoCoreBaseline(graph);
//        ego_core_del_line = EgoCore(graph);
//
//        Print(ego_core_del_line,"ego_core_del_line");
//        for(int i = 0; i < ego_core_del_line.size();i++) sort(ego_core_del_line[i].del_vertex_.begin(), ego_core_del_line[i].del_vertex_.end());
//        for(int i = 0; i < ego_core_del_line_bl.size();i++) sort(ego_core_del_line_bl[i].del_vertex_.begin(), ego_core_del_line_bl[i].del_vertex_.end());
//    }while(Compapre(ego_core_del_line,ego_core_del_line_bl) == 1);
//    graph.OutputOriginalGraph();
//    Print(ego_core_del_line,"ego_core_del_line");
//    Print(ego_core_del_line_bl,"ego_core_del_line_bl");
//
//}
//void TestClique(){
//    Graph graph;
//    graph.InputGraph();
//    for(int u = 0; u < graph.n_; u++){
//        sort(graph.edge_[u].begin(), graph.edge_[u].end());
//    }
//    vector<int> empty_set, P;
//    int mc_size = 0;
//    for(int i = 0; i < graph.n_; i++) P.push_back(i);
//
//    BasicMCE(graph, P, empty_set, empty_set, mc_size);
//    graph.OutputOriginalGraph();
//    cout<<mc_size<<endl;
//
//}
//void CompareTrussandEgocore(){
//    do{
//        Graph graph;
//        graph.RandomInputGraph();
//        Truss_sup truss_sup = FindTruss(graph);
//        int max_truss_k = 0;
//        for (int i = 0; i < graph.m_; i++) max_truss_k = max(max_truss_k, truss_sup[i].sup_);
//        EgoCoreDelLine ego_core_del_line = EgoCoreBaseline(graph);
//        int max_ego_core_k = ego_core_del_line[ego_core_del_line.size()-1].k_;
//        cout<<"Truss_sup'k="<<max_truss_k<<" "<<"ego_core'k="<<max_ego_core_k<<endl;
//
//        Graph truss = BuildTruss(truss_sup, max_truss_k);
//        Graph ego_core = BuildCorewithIndex(graph, ego_core_del_line, max_ego_core_k);
//        if(ego_core.n_ != ego_core_del_line[ego_core_del_line.size()-1].del_vertex_.size())
//            cout<<ego_core.n_<< " "<< ego_core_del_line[ego_core_del_line.size()-1].del_vertex_.size()<<endl;
//        assert(ego_core.n_ == ego_core_del_line[ego_core_del_line.size()-1].del_vertex_.size());
//        cout<<"Truss_n="<<truss.n_<<"ege_core_n="<<ego_core.n_<<endl;
//        cout<<"Truss_m="<<truss.m_<<"ege_core_m="<<ego_core.m_<<endl;
//        if(max_truss_k + 2 < max_ego_core_k){
//            graph.OutputGraph();
//            break;
//        }
//    }while(1);
//}

void MakeData(char *argv[]) {
    freopen(argv[1], "w", stdout);
    int n = 300, m = 100;
    cout << n << " " << m << endl;
    vector<vector<bool> >edge(n + 1, vector<bool>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        int x = rand() % n + 1, y = rand() % n + 1;
        while (x == y || edge[x][y]) x = rand() % n + 1, y = rand() % n + 1;
        edge[x][y] = 1;
        edge[y][x] = 1;
        cout << x << " " << y << endl;
    }

    int max_attribute = 5;
    cout << max_attribute << endl;
    for (int i = 1; i <= n; ++i) {
        int k = rand () % max_attribute;
        cout << k << " ";
        vector<bool> used(max_attribute + 1, 0);
        for (int i = 0; i < k; ++i) {
            int x =  rand() % max_attribute + 1;
            while(used[x]) x = rand() % max_attribute + 1;
            used[x] = 1;
            cout << x << " ";
        }
        cout << endl;

    }
    freopen(argv[2], "w", stdout);
    int nq = rand() % max_attribute  + 1, ns = min(10, rand() % n + 1);
    cout << nq << " " << ns << endl;
    vector<bool> used(max_attribute + 1, 0);
    for (int i = 1; i <= nq; ++i) {
        int x = rand() % max_attribute + 1;
        while(used[x]) x = rand() % max_attribute + 1;
        used[x] = 1;
        int number = min(5,rand() % (ns + 1));
        ns -= number;
        cout << x << " " << number << endl;
    }
}
int main(int argc, char *argv[]) {

    srand(time(NULL));

//    MakeData(argv);
    freopen("output.txt" , "a" , stdout);

    Graph graph;
    graph.InputGraph((string)argv[1]);
    graph.InputAttributes((string)argv[2]);

    printf("%s %d\n","Graph size:",graph.n_);


    freopen(("./cmake-build-debug/" + (string)argv[3]).c_str(), "r", stdin);
    int n;
    read(n);

    printf("%s %d\n","query size",n);
    fclose(stdout);

    vector <int> line;
    int maxsize, querynumber;
    int i ;
//#pragma omp parallel shared(default) private(i) 
//{
     
//#pragma omp for schedule(dynamic) nowait
    for(i = 0; i < n; i++){
        read(maxsize);read(querynumber);
        line.push_back(maxsize);
        line.push_back(querynumber);
        for(int j =0; j < querynumber; j++){
            int attribute, number;
            read(attribute); read(number);
            line.push_back(attribute);
            line.push_back(number);
        }
        cerr << i <<endl;
        //每行query初始化
        Query query(graph.n_, line);
        freopen("output.txt" , "a" , stdout);
        printf("\n");
        printf("%s\n", "**************************************************************");
        printf("%s%d\n","Finish read query ",i+1);
        query.CountAttributes(graph);

       // clock_t start,finish; //定义开始，结束变量
        cerr << i <<endl;
       // printf("开始计算\n");
       //  start = clock();//初始化开始时间
         FindCore(graph); 
	 double start,finish;
         start = omp_get_wtime();
         query.Start(graph);
         
//        Graph new_gra =  query.NewGraph(graph); 
 //       query.Start(new_gra);
         finish = omp_get_wtime();
       // finish = clock();//初始化结束时间
        printf("计算结束\n");
        // double duration = (double)(finish - start) / CLOCKS_PER_SEC;//转换浮点型
        double duration = finish -start;
        printf("%s %lf %s\n", "TestDataset:", duration, "seconds");
        query.Output();
        printf("%s %d\n","Finish",i+1);
        cerr << i <<endl;
        fclose(stdout);
        line.clear();
    }

//}
    cerr << "Finish" << endl;
    return 0;
}
