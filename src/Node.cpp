#include "Node.h"

Node::Node(int nodeValue) : value(nodeValue) {

}

void Node::ResetNode(void) {
    for (auto it = nextEdges.begin(); it != nextEdges.end();)
    {
        (*it).first->prevEdges.erase(this);
        it = nextEdges.erase(it);
    }
    for (auto it = prevEdges.begin(); it != prevEdges.end();)
    {
        (*it).first->nextEdges.erase(this);
        it = this->prevEdges.erase(it);
    }
}

int Node::NextEdgesCount(void) {
    return nextEdges.size();
}

int Node::PrevEdgesCount(void) {
    return prevEdges.size();
}

std::unordered_map<Node*, int>* Node::GetNextEdges(void) {
    return &nextEdges;
}

std::unordered_map<Node*, int>* Node::GetPrevEdges(void) {
    return &prevEdges;
}

int Node::GetValue(void) {
    return value;
}

bool Node::AddEdge(Node* nextNode, int weight) {
    if (weight < 0 || nextEdges.find(nextNode) != nextEdges.end() || nextNode == this) {
        return false;
    }
    else {
        nextEdges[nextNode] = weight;
        nextNode->prevEdges[this] = weight;
        return true;
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
