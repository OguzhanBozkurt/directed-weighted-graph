#include "Node.h"
#include <gtest/gtest.h>

class NodeTest : public testing::Test {
protected:
    Node* nodeA;
    Node* nodeB;
    Node* nodeC;
    Node* nodeD;

    virtual void SetUp() {
        nodeA = new Node(1);
        nodeB = new Node(2);
        nodeC = new Node(3);
        nodeD = new Node(4);
    }

    virtual void TearDown() {
        delete nodeA;
        delete nodeB;
        delete nodeC;
        delete nodeD;
    }
};

TEST_F(NodeTest, AddEdge){
    //Add an edge
    EXPECT_TRUE(nodeA->AddEdge(nodeB, 5));

    //Add an existing edge
    EXPECT_FALSE(nodeA->AddEdge(nodeB, 5));

    //Add an existing edge with different weight
    EXPECT_FALSE(nodeA->AddEdge(nodeB, 6));

    //Add an existing edge with negative weight
    EXPECT_FALSE(nodeA->AddEdge(nodeC, -1));

    //Add itself
    EXPECT_FALSE(nodeA->AddEdge(nodeA, 3));
}

TEST_F(NodeTest, DeleteEdge) {
    //Add edges in order to delete in the next steps
    //       > nodeB
    //      /        \
    //nodeA           > nodeD
    //      \        /
    //       > nodeC
    EXPECT_TRUE(nodeA->AddEdge(nodeB, 5));
    EXPECT_TRUE(nodeA->AddEdge(nodeC, 6));
    EXPECT_TRUE(nodeB->AddEdge(nodeD, 7));
    EXPECT_TRUE(nodeC->AddEdge(nodeD, 8));

    //Try to delete an unconnected edge
    EXPECT_FALSE(nodeA->DeleteEdge(nodeD));
    EXPECT_FALSE(nodeB->DeleteEdge(nodeA));
    EXPECT_FALSE(nodeC->DeleteEdge(nodeA));
    EXPECT_FALSE(nodeD->DeleteEdge(nodeB));
    EXPECT_FALSE(nodeD->DeleteEdge(nodeC));

    //Delete itself
    EXPECT_FALSE(nodeA->DeleteEdge(nodeA));
    EXPECT_FALSE(nodeD->DeleteEdge(nodeD));

    //Delete all edges
    EXPECT_TRUE(nodeA->DeleteEdge(nodeB));
    EXPECT_TRUE(nodeA->DeleteEdge(nodeC));
    EXPECT_TRUE(nodeB->DeleteEdge(nodeD));
    EXPECT_TRUE(nodeC->DeleteEdge(nodeD));
}
