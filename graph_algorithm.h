//
// Created by Jiyang Gong on 2020-04-08.
//

#ifndef COMMUNITY_GRAPH_ALGORITHM_H
#define COMMUNITY_GRAPH_ALGORITHM_H
#include "graph.h"
#define Test
class Query {
 public:
  int query_maxsize_, query_sum_, cost_, count_;
  int find_core_k_;
  // theory k core
  int theory_k_min;
  int theory_k_max;
  int theory_size_min;
  int theory_size_max;
  double check_time;
  double search_time;
  double reid_time;
  vector<int> search_core_, find_core_;
  vector<int> choose_;
  vector<int> id_;
  map<int, int> select_attr;
  vector<tuple<int, int>> queries;
  map<int,int> querymap;
  Query(int n, vector<int> line);
  Query(string input_str);
  void Output();
  void Start(const Graph &graph);
  void CountAttributes(const Graph &graph);
  Graph NewGraph(const Graph &graph);
 private:
  Graph ReidGraph(const Graph &graph, vector<int> & id , int st);
//  Graph NewGraph(const Graph &graph);
  bool ConditionAttr(Graph &graph);
  Graph OptGraph(const Graph &graph, vector<int> & id, int st);
  bool Check(const Graph &graph);
  bool FindMatch(BiGraph &bigraph);
  void Search(const Graph &graph, int x);
  int ExpectedKCore(const Graph &graph, int limit);
  vector<int> StartID(Graph graph);
  vector<int> NeighborID(Graph graph, int x);
};

#endif //COMMUNITY_GRAPH_ALGORITHM_H
