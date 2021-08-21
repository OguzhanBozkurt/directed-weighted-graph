#include "Node.h"
#include "Graph.h"
#include "WeightedGraph.h"

int main(int argc, char** argv){
    Node* nodeA = new Node(1);
    Node* nodeB = new Node(2);
    Node* nodeC = new Node(3);
    Node* nodeD = new Node(4);

    WeightedGraph graph;

    nodeA->AddEdge(nodeB, 5);
    nodeB->AddEdge(nodeC, 6);
    nodeC->AddEdge(nodeD, 7);
    nodeD->AddEdge(nodeA, 8);

    nodeB->DeleteEdge(nodeD);
    nodeB->DeleteEdge(nodeB);
    nodeB->DeleteEdge(nodeC);

    graph.AddNode(nodeA);
    graph.AddNode(nodeB);
    graph.AddNode(nodeC);
    graph.AddNode(nodeD);

}