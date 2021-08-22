#ifndef _WEIGHTED_GRAPH_H_
#define _WEIGHTED_GRAPH_H_

#include "Graph.h"
#include "Node.h"
#include <vector>

class WeightedGraph : public Graph{
public:
    WeightedGraph() = default;
    WeightedGraph(const WeightedGraph& graph) = default;
    bool AddNode(Node* node);
    bool DeleteNode(Node* node);
    std::vector<Node*> FindShortestPath(Node* from, Node* to);

private:
    std::unordered_map<Node*, std::unordered_map<Node*, std::vector<Node*>>> shortestPaths;
    bool IsSPTAlreadyCalculated(Node* from);
};

#endif //_WEIGHTED_GRAPH_H_
