#ifndef _WEIGHTED_GRAPH_H_
#define _WEIGHTED_GRAPH_H_

#include <set>
#include "Graph.h"
#include "Node.h"

class WeightedGraph : public Graph{
public:
    WeightedGraph() {};
    WeightedGraph(std::set<Node*> nodeList);
};

#endif //_WEIGHTED_GRAPH_H_
