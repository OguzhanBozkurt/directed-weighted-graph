#include "Graph.h"
#include <unordered_map>

Graph::Graph(){

}

Graph::Graph(const Graph& graph) {
    int size = graph.nodes.size();
    std::unordered_map<Node*, Node*> nodeMap;
    std::unordered_map<Node*, int>* targetNextEdges;
    for (auto it = graph.nodes.begin(); it != graph.nodes.end(); it++)
    {
        Node* newNode = new Node((*it)->GetValue());
        nodes.insert(newNode);
        nodeMap[*it] = newNode;
    }

    for (auto it = graph.nodes.begin(); it != graph.nodes.end(); it++)
    {
        targetNextEdges = (*it)->GetNextEdges();
        for (auto it2 = targetNextEdges->begin(); it2 != targetNextEdges->end(); it2++) {
            nodeMap[*it]->AddEdge(nodeMap[it2->first], it2->second);
        }
    }
}

Graph::~Graph() {
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        delete *it;
    }
}

bool Graph::AddNode(Node* node) {
    if (nodes.find(node) == nodes.end()) {
        nodes.insert(node);
        return true;
    }
    else {
        return false;
    }
}

bool Graph::DeleteNode(Node* node) {
    if (nodes.find(node) != nodes.end()) {
        nodes.erase(node);
        return true;
    }
    else {
        return false;
    }
}

int Graph::Size(void) {
	return nodes.size();
}

bool Graph::IsAcyclic(void) {
	Graph tempGraph(*this);
	bool isLeafFound = false;

	while (tempGraph.Size() != 0)
	{
		isLeafFound = false;
		for (auto it = tempGraph.nodes.begin(); it != tempGraph.nodes.end(); it++) {
			if ((*it)->NextEdgesCount() == 0) {
				(*it)->ResetNode();
				tempGraph.nodes.erase((*it));
				isLeafFound = true;
				break;
			}
		}
		if (!isLeafFound)
			return false;
	}

	return true;
}
