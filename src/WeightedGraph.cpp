#include <unordered_map>
#include "WeightedGraph.h"

static Node* findTheSmallestUnvisitedNode(
	std::unordered_map<Node*, int>& dist,
	std::set<Node*>& unvisitedNodes);

bool WeightedGraph::AddNode(Node* node) {
	shortestPaths.clear();
	return Graph::AddNode(node);
}

bool WeightedGraph::DeleteNode(Node* node) {
	shortestPaths.clear();
	return Graph::DeleteNode(node);
}

std::vector<Node*> WeightedGraph::FindShortestPath(Node* from, Node* to) {
	std::set<Node*> unvisitedNodes = nodes;
	std::unordered_map<Node*, int> dist;
	std::unordered_map<Node*, std::vector<Node*>> paths;
	std::unordered_map<Node*, int>* nextEdges;
	Node* currentNode = from;

	if (!IsSPTAlreadyCalculated(from)) {
		// Initialize dist and unvisited nodes
		for (auto it = nodes.begin(); it != nodes.end(); it++) {
			dist[*it] = 0x7FFFFFFF;
			unvisitedNodes.insert(*it);
			paths[*it].push_back(currentNode);
		}
		dist[from] = 0;

		while (unvisitedNodes.size() != 0 && currentNode != nullptr)
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

		shortestPaths[from] = paths;
	}

	return shortestPaths[from][to];
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

bool WeightedGraph::IsSPTAlreadyCalculated(Node* from) {
	return shortestPaths.find(from) != shortestPaths.end();
}
