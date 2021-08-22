#include "Node.h"
#include "Graph.h"
#include "WeightedGraph.h"

void findSmallest1(void) {
    Node* nodeA = new Node(1);
    Node* nodeB = new Node(2);
    Node* nodeC = new Node(3);
    Node* nodeD = new Node(4);
    Node* nodeE = new Node(5);
    Node* nodeF = new Node(6);
    Node* nodeG = new Node(7);

    nodeA->AddEdge(nodeB, 1);
    nodeA->AddEdge(nodeC, 3);
    nodeB->AddEdge(nodeD, 1);
    nodeC->AddEdge(nodeD, 3);
    nodeD->AddEdge(nodeE, 3);
    nodeD->AddEdge(nodeF, 1);
    nodeF->AddEdge(nodeE, 1);
    nodeF->AddEdge(nodeG, 3);
    nodeG->AddEdge(nodeE, 3);

    WeightedGraph graph;
    graph.AddNode(nodeA);
    graph.AddNode(nodeB);
    graph.AddNode(nodeC);
    graph.AddNode(nodeD);
    graph.AddNode(nodeE);
    graph.AddNode(nodeF);
    graph.AddNode(nodeG);

    graph.FindShortestPath(nodeA, nodeE);
}

void findSmallest2(void) {
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

    WeightedGraph graph;
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
}

void findSmallest3(void) {
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

    WeightedGraph graph;
    graph.AddNode(node1);
    graph.AddNode(node2);
    graph.AddNode(node3);
    graph.AddNode(node4);
    graph.AddNode(node5);
    graph.AddNode(node6);
    graph.AddNode(node7);
    graph.AddNode(node8);

    std::vector<Node*> shortestPath = graph.FindShortestPath(node1, node5);
}

int main(int argc, char** argv){
    Node* nodeA = new Node(1);
    Node* nodeB = new Node(2);
    Node* nodeC = new Node(3);
    Node* nodeD = new Node(4);

    WeightedGraph graph;

    findSmallest3();

    /*nodeA->AddEdge(nodeB, 5);
    nodeB->AddEdge(nodeC, 6);
    nodeC->AddEdge(nodeD, 7);
    nodeD->AddEdge(nodeA, 8);*/

    nodeA->AddEdge(nodeB, 5);
    nodeA->AddEdge(nodeC, 6);
    nodeB->AddEdge(nodeD, 7);
    nodeC->AddEdge(nodeD, 8);

    /*nodeB->DeleteEdge(nodeD);
    nodeB->DeleteEdge(nodeB);
    nodeB->DeleteEdge(nodeC);*/

    graph.AddNode(nodeA);
    graph.AddNode(nodeB);
    graph.AddNode(nodeC);
    graph.AddNode(nodeD);

    WeightedGraph graph2(graph);

    //nodeB->ResetNode();

    bool isAcyclic = graph.IsAcyclic();

}
