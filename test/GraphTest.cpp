#include "Graph.h"
#include <gtest/gtest.h>

class GraphTest : public testing::Test {
protected:
    Graph graph;
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

    }
};

TEST_F(GraphTest, AddNode){
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

TEST_F(GraphTest, DeleteNode) {
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

TEST_F(GraphTest, IsAcyclic1) {
    //Add edges for this test case
    //       > nodeB
    //      /        \
    //nodeA           > nodeD
    //      \        /
    //       > nodeC
    EXPECT_TRUE(graph.AddNode(nodeA));
    EXPECT_TRUE(graph.AddNode(nodeB));
    EXPECT_TRUE(graph.AddNode(nodeC));
    EXPECT_TRUE(graph.AddNode(nodeD));

    EXPECT_TRUE(graph.IsAcyclic());
}

TEST_F(GraphTest, IsAcyclic2) {
    nodeA->ResetNode();
    nodeB->ResetNode();
    nodeC->ResetNode();
    nodeD->ResetNode();

    //Add edges for this test case
    //nodeA --> nodeB 
    //  ^         |
    //  |         |
    //  |         v
    //nodeD <-- nodeC

    nodeA->AddEdge(nodeB, 5);
    nodeB->AddEdge(nodeC, 6);
    nodeC->AddEdge(nodeD, 7);
    nodeD->AddEdge(nodeA, 8);

    EXPECT_TRUE(graph.AddNode(nodeA));
    EXPECT_TRUE(graph.AddNode(nodeB));
    EXPECT_TRUE(graph.AddNode(nodeC));
    EXPECT_TRUE(graph.AddNode(nodeD));

    EXPECT_FALSE(graph.IsAcyclic());
}

TEST_F(GraphTest, IsAcyclic3) {
    nodeA->ResetNode();
    nodeB->ResetNode();
    nodeC->ResetNode();
    nodeD->ResetNode();

    //Add edges for this test case
    //       > nodeB < 
    //      /         \
    //nodeA            > nodeD
    //      \         /
    //       > nodeC

    nodeA->AddEdge(nodeB, 5);
    nodeA->AddEdge(nodeC, 6);
    nodeB->AddEdge(nodeD, 7);
    nodeC->AddEdge(nodeD, 8);
    nodeD->AddEdge(nodeB, 8);

    EXPECT_TRUE(graph.AddNode(nodeA));
    EXPECT_TRUE(graph.AddNode(nodeB));
    EXPECT_TRUE(graph.AddNode(nodeC));
    EXPECT_TRUE(graph.AddNode(nodeD));

    EXPECT_FALSE(graph.IsAcyclic());
}

TEST_F(GraphTest, IsAcyclic4) {
    nodeA->ResetNode();
    nodeB->ResetNode();
    nodeC->ResetNode();
    nodeD->ResetNode();

    //Add edges for this test case
    //       > nodeB
    //      /        \
    //nodeA           > nodeD
    //  ^   \        /    |
    //  |    > nodeC      |
    //  |                 |
    //  -------------------

    nodeA->AddEdge(nodeB, 5);
    nodeA->AddEdge(nodeC, 6);
    nodeB->AddEdge(nodeD, 7);
    nodeC->AddEdge(nodeD, 8);
    nodeD->AddEdge(nodeA, 8);

    EXPECT_TRUE(graph.AddNode(nodeA));
    EXPECT_TRUE(graph.AddNode(nodeB));
    EXPECT_TRUE(graph.AddNode(nodeC));
    EXPECT_TRUE(graph.AddNode(nodeD));

    EXPECT_FALSE(graph.IsAcyclic());
}

TEST_F(GraphTest, IsAcyclic5) {
    nodeA->ResetNode();
    nodeB->ResetNode();
    nodeC->ResetNode();
    nodeD->ResetNode();
    nodeE->ResetNode();

    //Add edges for this test case
    //          nodeB
    //            |
    //            v  
    //nodeA --> nodeE <-- nodeC
    //            ^    
    //            |      
    //          nodeD                

    nodeA->AddEdge(nodeE, 5);
    nodeB->AddEdge(nodeE, 6);
    nodeC->AddEdge(nodeE, 7);
    nodeD->AddEdge(nodeE, 8);

    EXPECT_TRUE(graph.AddNode(nodeA));
    EXPECT_TRUE(graph.AddNode(nodeB));
    EXPECT_TRUE(graph.AddNode(nodeC));
    EXPECT_TRUE(graph.AddNode(nodeD));
    EXPECT_TRUE(graph.AddNode(nodeE));

    EXPECT_TRUE(graph.IsAcyclic());
}

TEST_F(GraphTest, IsAcyclic6) {
    nodeA->ResetNode();

    //Add edges for this test case
    //          nodeA

    EXPECT_TRUE(graph.AddNode(nodeA));

    EXPECT_TRUE(graph.IsAcyclic());
}

TEST_F(GraphTest, Size) {
    EXPECT_EQ(graph.Size(), 0);
    EXPECT_TRUE(graph.AddNode(nodeA));
    EXPECT_EQ(graph.Size(), 1);
    EXPECT_TRUE(graph.AddNode(nodeB));
    EXPECT_EQ(graph.Size(), 2);
    EXPECT_TRUE(graph.AddNode(nodeC));
    EXPECT_EQ(graph.Size(), 3);
    EXPECT_TRUE(graph.AddNode(nodeD));
    EXPECT_EQ(graph.Size(), 4);
    EXPECT_TRUE(graph.DeleteNode(nodeD));
    EXPECT_EQ(graph.Size(), 3);
    EXPECT_TRUE(graph.DeleteNode(nodeC));
    EXPECT_EQ(graph.Size(), 2);
    EXPECT_TRUE(graph.DeleteNode(nodeB));
    EXPECT_EQ(graph.Size(), 1);
    EXPECT_TRUE(graph.DeleteNode(nodeA));
    EXPECT_EQ(graph.Size(), 0);
}
