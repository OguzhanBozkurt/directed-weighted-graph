#ifndef _NODE_H_
#define _NODE_H_

#include <vector>
#include <unordered_map>

class Node {
public:
    /**
     * Creates a node object with the given node value
     * 
     * @param[in] nodeValue Node value of the new node
     */
    explicit Node(int nodeValue);

    /**
     * Adds a next edge to a node object
     * 
     * @param[in] nextNode  Next node object to be directed from this node
     * @param[in] weight    Weight of the edge
     * 
     * @return  false   : If this node is equal to nextNode OR weight is negative OR nextNode is already 
     *                  added
     *          true    : Otherwise
     */
    bool AddEdge(Node* nextNode, int weight);

    /**
     * Deletes a next edge to a node object
     * 
     * @param[in] nextNode  Next node object to be deleted from this node
     * 
     * @return  true    : If the nextNode is added with AddEdge before DeleteEdge is called
     *          false   : Otherwise
     */
    bool DeleteEdge(Node* nextNode);

    /**
     * Resets the edges of a node object
     * 
     * nextEdges and prevEdges are deleted but value of the node remains same.
     */
    void ResetNode(void);

    /**
     * Returns the value of the node object
     * 
     * @return  value of the node
     */
    int GetValue(void);

    /**
     * Returns the number of next edges of a node object
     * 
     * @return  count of the next edges
     */
    int NextEdgesCount(void);

    /**
     * Returns the number of previous edges of a node object
     * 
     * @return  count of the previous edges
     */
    int PrevEdgesCount(void);

    /**
     * Returns the next edges of a node object
     * 
     * @return  pointer to a unorderep_map of Node* to int object. int value is the weight of that 
     *          edge
     */
    std::unordered_map<Node*, int>* GetNextEdges(void);

    /**
     * Returns the previous edges of a node object
     * 
     * @return  pointer to a unorderep_map of Node* to int object. int value is the weight of that 
     *          edge
     */
    std::unordered_map<Node*, int>* GetPrevEdges(void);

private:
    int value;
    std::unordered_map<Node*, int> nextEdges;
    std::unordered_map<Node*, int> prevEdges;
};

#endif //_NODE_H_
