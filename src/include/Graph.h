#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <set>
#include "Node.h"

class Graph {
public:
    /**
     * Creates an empty graph object
     */
    Graph();

    /**
     * Creates a graph object from an existing graph
     * 
     * @param[in] graph Input graph which will be copied
     */
    Graph(const Graph& graph);

    ~Graph();

    /**
     * Adds a node to the graph
     * 
     * @param[in] node  Pointer to the node which will be added to this graph 
     * 
     * @return  false   : If node is already added
     *          true    : Otherwise
     */
    bool AddNode(Node* node);

    /**
     * Deletes a node from the graph
     * 
     * @param[in] node  Pointer to the node which will be deleted from this graph 
     * 
     * @return  false   : If node is not added with AddNode beforehand
     *          true    : Otherwise
     */
    bool DeleteNode(Node* node);

    /**
     * Returns whether the graph is acyclic or not
     * 
     * Acyclic graph does not contain any cycles in it.
     * 
     * @return  false   : If the graph is cyclic
     *          true    : If the graph is acyclic
     */
    bool IsAcyclic(void);

    /**
     * Returns the count of the nodes on the graph
     * 
     * @return  count of the nodes
     */
    int Size(void);

protected:
    std::set<Node*> nodes;
};

#endif //_GRAPH_H_
