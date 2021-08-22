#include <unordered_map>
#include "WeightedGraph.h"

static Node* findTheSmallestUnvisitedNode(
	std::unordered_map<Node*, int>& dist,
	std::set<Node*>& unvisitedNodes);

std::vector<Node*> WeightedGraph::FindShortestPath(const Node* from, const Node* to) {
	std::set<Node*> unvisitedNodes = nodes;
	std::unordered_map<Node*, int> dist;
	std::unordered_map<Node*, std::vector<Node*>> paths;
	std::unordered_map<Node*, int>* nextEdges;
	Node* currentNode = &from;

	// Initialize dist and unvisited nodes
	for (auto it = nodes.begin(); it != nodes.end(); it++) {
		dist[*it] = 0x7FFFFFFF;
		unvisitedNodes.insert(*it);
		paths[*it].push_back(currentNode);
	}
	dist[from] = 0;

	while (unvisitedNodes.size() != 0)
	{
		nextEdges = currentNode->GetNextEdges();
		for (auto it = nextEdges->begin(); it != nextEdges->end(); it++) {
			// Current distance and path is updated
			if (dist[it->first] > dist[currentNode] + it->second) {
				dist[it->first] = dist[currentNode] + it->second;
				paths[it->first] = paths[currentNode];
				paths[it->first].push_back(it->first);
			}
		}
		// Delete the node from unvisited nodes list
		if (unvisitedNodes.find(currentNode) != unvisitedNodes.end()) {
			unvisitedNodes.erase(currentNode);
		}
		currentNode = findTheSmallestUnvisitedNode(dist, unvisitedNodes);
	}

	return paths[to];
}

static Node* findTheSmallestUnvisitedNode(
	std::unordered_map<Node*, int>& dist,
	std::set<Node*>& unvisitedNodes) {
	int smallestDist = 0x7FFFFFFF;
	Node* smallestDistNode = nullptr;

	for (auto it = unvisitedNodes.begin(); it != unvisitedNodes.end(); it++) {
		if (dist[*it] < smallestDist) {
			smallestDistNode = *it;
			smallestDist = dist[*it];
		}
	}

	return smallestDistNode;
}
