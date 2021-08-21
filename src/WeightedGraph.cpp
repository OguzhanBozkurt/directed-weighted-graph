#include "WeightedGraph.h"

int WeightedGraph::Size(void) {
	return nodes.size();
}

bool WeightedGraph::IsAcyclic(void) {
	WeightedGraph tempGraph(*this);
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
