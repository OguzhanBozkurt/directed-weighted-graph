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

TEST_F(NodeTest, GetNextAndPrevEdges) {
    //Add edges for this test case
    //       > nodeB
    //      /        \
    //nodeA           > nodeD
    //      \        /
    //       > nodeC
    EXPECT_TRUE(nodeA->AddEdge(nodeB, 5));
    EXPECT_TRUE(nodeA->AddEdge(nodeC, 6));
    EXPECT_TRUE(nodeB->AddEdge(nodeD, 7));
    EXPECT_TRUE(nodeC->AddEdge(nodeD, 8));

    std::unordered_map<Node*, int>* nextEdges = nodeA->GetNextEdges();
    
    //B and C are next nodes of the A and the weight of the edges are correct
    EXPECT_EQ((*nextEdges).size(), 2);
    EXPECT_TRUE(nextEdges->find(nodeB) != nextEdges->end());
    EXPECT_EQ((*nextEdges)[nodeB], 5);
    EXPECT_TRUE(nextEdges->find(nodeC) != nextEdges->end());
    EXPECT_EQ((*nextEdges)[nodeC], 6);

    //D is not a next node of the A
    EXPECT_TRUE(nextEdges->find(nodeD) == nextEdges->end());

    std::unordered_map<Node*, int>* prevEdges = nodeA->GetPrevEdges();
    //A does not have a previous node
    EXPECT_EQ((*prevEdges).size(), 0);

    //A is the only previous node of the B
    prevEdges = nodeB->GetPrevEdges();
    EXPECT_EQ((*prevEdges).size(), 1);
    EXPECT_TRUE(prevEdges->find(nodeA) != prevEdges->end());
    EXPECT_EQ((*prevEdges)[nodeA], 5);
}

TEST_F(NodeTest, GetNextAndPrevEdgesCount) {
    // Next and previous node count of all nodes are 0 at start
    EXPECT_EQ(nodeA->PrevEdgesCount(), 0);
    EXPECT_EQ(nodeA->NextEdgesCount(), 0);

    EXPECT_EQ(nodeB->PrevEdgesCount(), 0);
    EXPECT_EQ(nodeB->NextEdgesCount(), 0);

    EXPECT_EQ(nodeC->PrevEdgesCount(), 0);
    EXPECT_EQ(nodeC->NextEdgesCount(), 0);

    EXPECT_EQ(nodeD->PrevEdgesCount(), 0);
    EXPECT_EQ(nodeD->NextEdgesCount(), 0);

    //Add edges for this test case
    //       > nodeB
    //      /        \
    //nodeA           > nodeD
    //      \        /
    //       > nodeC
    EXPECT_TRUE(nodeA->AddEdge(nodeB, 5));
    EXPECT_TRUE(nodeA->AddEdge(nodeC, 6));
    EXPECT_TRUE(nodeB->AddEdge(nodeD, 7));
    EXPECT_TRUE(nodeC->AddEdge(nodeD, 8));

    // Next and previous node count of all nodes are updated
    EXPECT_EQ(nodeA->PrevEdgesCount(), 0);
    EXPECT_EQ(nodeA->NextEdgesCount(), 2);

    EXPECT_EQ(nodeB->PrevEdgesCount(), 1);
    EXPECT_EQ(nodeB->NextEdgesCount(), 1);

    EXPECT_EQ(nodeC->PrevEdgesCount(), 1);
    EXPECT_EQ(nodeC->NextEdgesCount(), 1);

    EXPECT_EQ(nodeD->PrevEdgesCount(), 2);
    EXPECT_EQ(nodeD->NextEdgesCount(), 0);
}

TEST_F(NodeTest, GetValue) {
    //Node values of the nodes are updated
    EXPECT_EQ(nodeA->GetValue(), 1);
    EXPECT_EQ(nodeB->GetValue(), 2);
    EXPECT_EQ(nodeC->GetValue(), 3);
    EXPECT_EQ(nodeD->GetValue(), 4);
}

TEST_F(NodeTest, ResetNode) {
    //Add edges for this test case
    //       > nodeB
    //      /        \
    //nodeA           > nodeD
    //      \        /
    //       > nodeC
    EXPECT_TRUE(nodeA->AddEdge(nodeB, 5));
    EXPECT_TRUE(nodeA->AddEdge(nodeC, 6));
    EXPECT_TRUE(nodeB->AddEdge(nodeD, 7));
    EXPECT_TRUE(nodeC->AddEdge(nodeD, 8));

    //Reset the nodeB
    //
    //              
    //nodeA           > nodeD
    //      \        /
    //       > nodeC
    nodeB->ResetNode();
    
    //B is deleted and C is the only next node of the A
    std::unordered_map<Node*, int>* nextEdges = nodeA->GetNextEdges();
    EXPECT_EQ((*nextEdges).size(), 1);
    EXPECT_TRUE(nextEdges->find(nodeB) == nextEdges->end());
    EXPECT_TRUE(nextEdges->find(nodeC) != nextEdges->end());
    EXPECT_EQ(nodeA->NextEdgesCount(), 1);

    //B is deleted and C is the only previous node of the D
    std::unordered_map<Node*, int>* prevEdges = nodeD->GetPrevEdges();
    EXPECT_EQ((*prevEdges).size(), 1);
    EXPECT_TRUE(prevEdges->find(nodeB) == prevEdges->end());
    EXPECT_TRUE(prevEdges->find(nodeC) != prevEdges->end());
    EXPECT_EQ(nodeD->PrevEdgesCount(), 1);
}