
// Created by Jiyang Gong on 2019-03-26.
//

#ifndef Communtity_CORES_H
#define Communtity_CORES_H
#include "include.h"
#include "graph.h"
#include "condition.h"

class CoreDelVertex{
    public:
        int  k_;
        vector<int> del_vertex_;
};
typedef vector<CoreDelVertex> CoreDelLine;

class Cores{
    public:
        int k_;
        vector<int> vertex_;
};
class CoreGraph{
    public:
        int n_, k_;
        vector<int> vertex_;
        vector<int> exsit_vertex_;
        vector<int> deg_;
        unordered_map<int, int>  core_vertex_id_;
};
class CoreBucket{

    public:
        vector<int> bin_,pos_,vert_;
        int start_;
};
CoreDelLine  FindCore(Graph &graph);
Graph FindKCore(Graph graph, int k_degree);
bool CheckCoresDelLine(Graph graph, CoreDelLine cores_del_line);
Cores FindLeastColorCores(Graph graph, NeedColorList need_color_vertex_list, CoreDelLine cores_del_line);
Graph BuildCorewithIndex(Graph graph, CoreDelLine core_del_line, int core_k);
#endif //Communtity_CORES_H
