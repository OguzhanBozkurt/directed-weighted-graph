#include "WeightedGraph.h"
#include <gtest/gtest.h>

class WeightedGraphTest : public testing::Test {
protected:
    WeightedGraph graph;

    Node* node1;
    Node* node2;
    Node* node3;
    Node* node4;
    Node* node5;
    Node* node6;
    Node* node7;
    Node* node8;
    Node* node9;
    Node* node10;

    virtual void SetUp() {
        node1 = new Node(1);
        node2 = new Node(2);
        node3 = new Node(3);
        node4 = new Node(4);
        node5 = new Node(5);
        node6 = new Node(6);
        node7 = new Node(7);
        node8 = new Node(8);
        node9 = new Node(9);
        node10 = new Node(10);
    }

    virtual void TearDown() {
        delete node1;
        delete node2;
        delete node3;
        delete node4;
        delete node5;
        delete node6;
        delete node7;
        delete node8;
        delete node9;
        delete node10;
    }
};

TEST_F(WeightedGraphTest, AddNode){
    node1->AddEdge(node2, 5);
    node1->AddEdge(node3, 6);
    node2->AddEdge(node4, 7);
    node3->AddEdge(node4, 8);

    //Add a node
    EXPECT_TRUE(graph.AddNode(node1));
    EXPECT_TRUE(graph.AddNode(node2));
    EXPECT_TRUE(graph.AddNode(node3));
    EXPECT_TRUE(graph.AddNode(node4));

    //Add an existing node
    EXPECT_FALSE(graph.AddNode(node1));
    EXPECT_FALSE(graph.AddNode(node2));
    EXPECT_FALSE(graph.AddNode(node3));
    EXPECT_FALSE(graph.AddNode(node4));
}

TEST_F(WeightedGraphTest, DeleteNode) {
    node1->AddEdge(node2, 5);
    node1->AddEdge(node3, 6);
    node2->AddEdge(node4, 7);
    node3->AddEdge(node4, 8);
    
    //Add edges in order to delete in the next steps
    //       > node2
    //      /        \
    //node1           > node4
    //      \        /
    //       > node3
    EXPECT_TRUE(graph.AddNode(node1));
    EXPECT_TRUE(graph.AddNode(node2));
    EXPECT_TRUE(graph.AddNode(node3));
    EXPECT_TRUE(graph.AddNode(node4));

    //Try to delete an unconnected node
    EXPECT_FALSE(graph.DeleteNode(node5));

    //Delete all nodes
    EXPECT_TRUE(graph.DeleteNode(node1));
    EXPECT_TRUE(graph.DeleteNode(node2));
    EXPECT_TRUE(graph.DeleteNode(node3));
    EXPECT_TRUE(graph.DeleteNode(node4));

    //Try to delete all nodes again
    EXPECT_FALSE(graph.DeleteNode(node1));
    EXPECT_FALSE(graph.DeleteNode(node2));
    EXPECT_FALSE(graph.DeleteNode(node3));
    EXPECT_FALSE(graph.DeleteNode(node4));
}

TEST_F(WeightedGraphTest, FindShortestPath1) {
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
    EXPECT_EQ(shortestPath[0], node1);
    EXPECT_EQ(shortestPath[1], node2);
    EXPECT_EQ(shortestPath[2], node4);
    EXPECT_EQ(shortestPath[3], node6);
    EXPECT_EQ(shortestPath[4], node5);
    EXPECT_EQ(shortestPath.size(), 5);
}

TEST_F(WeightedGraphTest, FindShortestPath2) {
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
    EXPECT_EQ(shortestPath[0], node1);
    EXPECT_EQ(shortestPath[1], node3);
    EXPECT_EQ(shortestPath[2], node5);
    EXPECT_EQ(shortestPath[3], node9);
    EXPECT_EQ(shortestPath[4], node10);
    EXPECT_EQ(shortestPath.size(), 5);

    shortestPath = graph.FindShortestPath(node1, node8);
    EXPECT_EQ(shortestPath[0], node1);
    EXPECT_EQ(shortestPath[1], node2);
    EXPECT_EQ(shortestPath[2], node4);
    EXPECT_EQ(shortestPath[3], node8);
    EXPECT_EQ(shortestPath.size(), 4);
}

TEST_F(WeightedGraphTest, FindShortestPath3) {
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
    EXPECT_EQ(shortestPath[0], node1);
    EXPECT_EQ(shortestPath[1], node2);
    EXPECT_EQ(shortestPath[2], node6);
    EXPECT_EQ(shortestPath[3], node8);
    EXPECT_EQ(shortestPath[4], node7);
    EXPECT_EQ(shortestPath[5], node5);
    EXPECT_EQ(shortestPath.size(), 6);
}
