#include "Graph.h"

Graph::Graph(){

}

Graph::Graph(std::set<Node*> nodeList) : nodes(nodeList) {
    
}

bool Graph::AddNode(Node* nextNode) {
    if (nodes.find(nextNode) == nodes.end()) {
        nodes.insert(nextNode);
        return true;
    }
    else {
        return false;
    }
}

bool Graph::DeleteNode(Node* nextNode) {
    if (nodes.find(nextNode) != nodes.end()) {
        nodes.erase(nextNode);
        return true;
    }
    else {
        return false;
    }
}