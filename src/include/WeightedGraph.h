#ifndef _WEIGHTED_GRAPH_H_
#define _WEIGHTED_GRAPH_H_

#include "Graph.h"
#include "Node.h"
#include <vector>

class WeightedGraph : public Graph{
public:
    WeightedGraph() = default;
    WeightedGraph(const WeightedGraph& graph) = default;
    std::vector<Node*> FindShortestPath(const Node* from, const Node* to);
};

#endif //_WEIGHTED_GRAPH_H_
