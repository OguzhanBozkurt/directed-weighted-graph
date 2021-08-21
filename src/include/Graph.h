#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <set>
#include "Node.h"

class Graph {
public:
    Graph();
    Graph(const Graph& graph);
    ~Graph();
    bool AddNode(Node* node);
    bool DeleteNode(Node* node);
    bool IsAcyclic(void);
    int Size(void);

protected:
    std::set<Node*> nodes;
};

#endif //_GRAPH_H_
