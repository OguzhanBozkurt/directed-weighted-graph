#include "Node.h"

Node::Node(int nodeValue) : value(nodeValue) {

}

bool Node::AddEdge(Node* nextNode, int weight) {
    if (nextEdges.find(nextNode) == nextEdges.end()) {
        nextEdges[nextNode] = weight;
        nextNode->prevEdges[this] = weight;
        return true;
    }
    else {
        return false;
    }
}

bool Node::DeleteEdge(Node* nextNode) {
    if (nextEdges.find(nextNode) != nextEdges.end()) {
        nextEdges.erase(nextNode);
        nextNode->prevEdges.erase(this);
        return true;
    }
    else {
        return false;
    }
}