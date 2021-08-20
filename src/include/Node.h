#ifndef _NODE_H_
#define _NODE_H_

#include <vector>
#include <unordered_map>

class Node {
public:
    explicit Node(int nodeValue);
    bool AddEdge(Node* nextNode, int weight);
    bool DeleteEdge(Node* nextNode);

private:
    int value;
    std::unordered_map<Node*, int> nextEdges;
    std::unordered_map<Node*, int> prevEdges;
};

#endif //_NODE_H_
