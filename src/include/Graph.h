#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <set>
#include "Node.h"

class Graph {
public:
    Graph();
    Graph(std::set<Node*> nodeList);
    bool AddNode(Node* nextNode);
    bool DeleteNode(Node* nextNode);

protected:
    std::set<Node*> nodes;
};

#endif //_GRAPH_H_
