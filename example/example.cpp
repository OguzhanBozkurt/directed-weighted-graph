#include <iostream>
#include "Node.h"
#include "Graph.h"
#include "WeightedGraph.h"

void printShortestPath(std::vector<Node*>& shortestPath) {
    std::cout << "Shortest path:\n";
    for (auto it = shortestPath.begin(); it != shortestPath.end(); it++) {
        std::cout << "Node" << (*it)->GetValue() << "\n";
    }
    std::cout << "\n";
}

void findSmallest1(void) {
    WeightedGraph graph;

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);

    node1->AddEdge(node2, 1);
    node1->AddEdge(node3, 3);
    node2->AddEdge(node4, 1);
    node3->AddEdge(node4, 3);
    node4->AddEdge(node5, 3);
    node4->AddEdge(node6, 1);
    node6->AddEdge(node5, 1);
    node6->AddEdge(node7, 3);
    node7->AddEdge(node5, 3);

    graph.AddNode(node1);
    graph.AddNode(node2);
    graph.AddNode(node3);
    graph.AddNode(node4);
    graph.AddNode(node5);
    graph.AddNode(node6);
    graph.AddNode(node7);

    std::vector<Node*> shortestPath = graph.FindShortestPath(node1, node5);
    printShortestPath(shortestPath);
}

void findSmallest2(void) {
    WeightedGraph graph;

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);
    Node* node9 = new Node(9);
    Node* node10 = new Node(10);

    node1->AddEdge(node2, 4);
    node1->AddEdge(node3, 1);
    node2->AddEdge(node4, 3);
    node3->AddEdge(node4, 7);
    node3->AddEdge(node5, 8);
    node4->AddEdge(node8, 5);
    node5->AddEdge(node6, 3);
    node5->AddEdge(node9, 1);
    node6->AddEdge(node7, 7);
    node7->AddEdge(node8, 3);
    node8->AddEdge(node5, 4);
    node9->AddEdge(node10, 5);

    graph.AddNode(node1);
    graph.AddNode(node2);
    graph.AddNode(node3);
    graph.AddNode(node4);
    graph.AddNode(node5);
    graph.AddNode(node6);
    graph.AddNode(node7);
    graph.AddNode(node8);
    graph.AddNode(node9);
    graph.AddNode(node10);

    std::vector<Node*> shortestPath = graph.FindShortestPath(node1, node10);
    printShortestPath(shortestPath);
}

void findSmallest3(void) {
    WeightedGraph graph;

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);

    node1->AddEdge(node2, 2);
    node1->AddEdge(node3, 1);
    node1->AddEdge(node4, 4);
    node2->AddEdge(node3, 5);
    node2->AddEdge(node5, 10);
    node2->AddEdge(node6, 2);
    node3->AddEdge(node1, 9);
    node3->AddEdge(node5, 11);
    node4->AddEdge(node3, 2);
    node5->AddEdge(node4, 7);
    node5->AddEdge(node7, 1);
    node6->AddEdge(node8, 3);
    node7->AddEdge(node5, 3);
    node7->AddEdge(node6, 2);
    node8->AddEdge(node7, 1);

    graph.AddNode(node1);
    graph.AddNode(node2);
    graph.AddNode(node3);
    graph.AddNode(node4);
    graph.AddNode(node5);
    graph.AddNode(node6);
    graph.AddNode(node7);
    graph.AddNode(node8);

    std::vector<Node*> shortestPath = graph.FindShortestPath(node1, node5);
    printShortestPath(shortestPath);
}

void isAcyclic1(void) {
    WeightedGraph graph;

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    node1->AddEdge(node2, 5);
    node2->AddEdge(node3, 6);
    node3->AddEdge(node4, 7);
    node4->AddEdge(node1, 8);

    graph.AddNode(node1);
    graph.AddNode(node2);
    graph.AddNode(node3);
    graph.AddNode(node4);

    bool isAcyclic = graph.IsAcyclic();
    std::cout << "Graph1 IsAcyclic = " << isAcyclic << "\n";
}

void isAcyclic2(void) {
    WeightedGraph graph;

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->AddEdge(node2, 5);
    node1->AddEdge(node3, 6);
    node2->AddEdge(node4, 7);
    node3->AddEdge(node4, 8);

    graph.AddNode(node1);
    graph.AddNode(node2);
    graph.AddNode(node3);
    graph.AddNode(node4);

    WeightedGraph graph2(graph);

    bool isAcyclic = graph2.IsAcyclic();

    std::cout << "Graph2 IsAcyclic = " << isAcyclic << "\n";
}

int main(int argc, char** argv){
    findSmallest1();
    findSmallest2();
    findSmallest3();

    isAcyclic1();
    isAcyclic2();
}
