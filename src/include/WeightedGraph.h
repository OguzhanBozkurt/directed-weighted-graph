#ifndef _WEIGHTED_GRAPH_H_
#define _WEIGHTED_GRAPH_H_

#include "Graph.h"
#include "Node.h"
#include <vector>

class WeightedGraph : public Graph{
public:
    /**
     * Creates an empty graph object
     */
    WeightedGraph() = default;

    /**
     * Creates a graph object from an existing graph
     * 
     * @param[in] graph Input graph which will be copied
     */
    WeightedGraph(const WeightedGraph& graph) = default;

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
     * Finds the shortest path between two nodes considering the weights of the edges
     * 
     * @param[in] from  Pointer to the start node 
     * @param[in] to    Pointer to the target node
     * 
     * @return  vector of nodes from "from" to "to" if a shortest path exist, otherwise returns 
     *          only the first node
     */
    std::vector<Node*> FindShortestPath(Node* from, Node* to);

private:
    std::unordered_map<Node*, std::unordered_map<Node*, std::vector<Node*>>> shortestPaths;
    bool IsSPTAlreadyCalculated(Node* from);
};

#endif //_WEIGHTED_GRAPH_H_
