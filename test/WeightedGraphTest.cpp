#include "WeightedGraph.h"
#include <gtest/gtest.h>

class WeightedGraphTest : public testing::Test {
protected:
    WeightedGraph graph;
    Node* nodeA;
    Node* nodeB;
    Node* nodeC;
    Node* nodeD;
    Node* nodeE;

    virtual void SetUp() {
        nodeA = new Node(1);
        nodeB = new Node(2);
        nodeC = new Node(3);
        nodeD = new Node(4);
        nodeE = new Node(5);

        nodeA->AddEdge(nodeB, 5);
        nodeA->AddEdge(nodeC, 6);
        nodeB->AddEdge(nodeD, 7);
        nodeC->AddEdge(nodeD, 8);
    }

    virtual void TearDown() {
        delete nodeA;
        delete nodeB;
        delete nodeC;
        delete nodeD;
        delete nodeE;
    }
};

TEST_F(WeightedGraphTest, AddNode){
    //Add a node
    EXPECT_TRUE(graph.AddNode(nodeA));
    EXPECT_TRUE(graph.AddNode(nodeB));
    EXPECT_TRUE(graph.AddNode(nodeC));
    EXPECT_TRUE(graph.AddNode(nodeD));

    //Add an existing node
    EXPECT_FALSE(graph.AddNode(nodeA));
    EXPECT_FALSE(graph.AddNode(nodeB));
    EXPECT_FALSE(graph.AddNode(nodeC));
    EXPECT_FALSE(graph.AddNode(nodeD));
}

TEST_F(WeightedGraphTest, DeleteNode) {
    //Add edges in order to delete in the next steps
    //       > nodeB
    //      /        \
    //nodeA           > nodeD
    //      \        /
    //       > nodeC
    EXPECT_TRUE(graph.AddNode(nodeA));
    EXPECT_TRUE(graph.AddNode(nodeB));
    EXPECT_TRUE(graph.AddNode(nodeC));
    EXPECT_TRUE(graph.AddNode(nodeD));

    //Try to delete an unconnected node
    EXPECT_FALSE(graph.DeleteNode(nodeE));

    //Delete all nodes
    EXPECT_TRUE(graph.DeleteNode(nodeA));
    EXPECT_TRUE(graph.DeleteNode(nodeB));
    EXPECT_TRUE(graph.DeleteNode(nodeC));
    EXPECT_TRUE(graph.DeleteNode(nodeD));

    //Try to delete all nodes again
    EXPECT_FALSE(graph.DeleteNode(nodeA));
    EXPECT_FALSE(graph.DeleteNode(nodeB));
    EXPECT_FALSE(graph.DeleteNode(nodeC));
    EXPECT_FALSE(graph.DeleteNode(nodeD));
}
