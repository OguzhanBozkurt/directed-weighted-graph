#ifndef _WEIGHTED_GRAPH_H_
#define _WEIGHTED_GRAPH_H_

#include <set>
#include "Graph.h"
#include "Node.h"

class WeightedGraph : public Graph{
public:
    WeightedGraph() = default;
    WeightedGraph(const WeightedGraph& graph) = default;
    bool IsAcyclic(void);
    int Size(void);
};

#endif //_WEIGHTED_GRAPH_H_
