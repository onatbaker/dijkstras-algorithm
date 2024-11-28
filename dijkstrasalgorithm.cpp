#include "graph.h"

int main()
{
	Graph graph;
	Graph graphObject = makeGraph(graph);

	std::vector<std::string> processed;

	std::string node = findLowestCostNode(graphObject.costs, processed);

	Dijkstra(graphObject);

	std::cout << "Shortest paths from 'start':" << std::endl;

	for (const auto& pair : graphObject.costs)
	{
		const auto& node = pair.first;
		const auto& cost = pair.second;
		std::cout << node << ": " << cost << std::endl;
	}

	std::cout << " ----------------------------------------- " << std::endl;
	printNeighbor(graphObject);
	printWeightOfEdges(graphObject);
}
