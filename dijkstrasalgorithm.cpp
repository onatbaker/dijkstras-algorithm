#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>

std::string findLowestCostNode(const std::unordered_map<std::string, double>& costs, const std::vector<std::string>& processed)
{
	double lowestCost = std::numeric_limits<double>::infinity();
	std::string lowestCostNode;

	for (const auto& pair : costs)
	{
		const auto& node = pair.first;
		const auto& cost = pair.second;

		if (cost < lowestCost && std::find(processed.begin(), processed.end(), node) == processed.end())
		{
			lowestCost = cost;
			lowestCostNode = node;
		}
	}

	return lowestCostNode;
}

int main()
{
	double inf = std::numeric_limits<double>::infinity();

	std::unordered_map<std::string, std::unordered_map<std::string, double>> graph;
	std::unordered_map<std::string, double> costs;
	std::unordered_map<std::string, std::string> parents;
	std::vector<std::string> processed;

	graph["start"]["a"] = 6;
	graph["start"]["b"] = 2;

	graph["a"]["fin"] = 1;

	graph["b"]["a"] = 3;
	graph["b"]["fin"] = 5;

	graph["fin"] = {};

	costs["a"] = 6;
	costs["b"] = 2;
	costs["fin"] = inf;

	parents["a"] = "start";
	parents["b"] = "start";
	parents["fin"] = "";

	std::string node = findLowestCostNode(costs, processed);
	while (!node.empty())
	{
		double cost = costs[node];
		const auto& neighbors = graph[node];

		for (const auto& pair : neighbors)
		{
			const auto& neighbor = pair.first;
			double weight = pair.second;
			double newCost = cost + weight;

			if (costs[neighbor] > newCost)
			{
				costs[neighbor] = newCost;
				parents[neighbor] = node;
			}
		}

		processed.push_back(node);
		node = findLowestCostNode(costs, processed);
	}

	std::cout << "Shortest paths from 'start':" << std::endl;

	for (const auto& pair : costs)
	{
		const auto& node = pair.first;
		const auto& cost = pair.second;
		std::cout << node << ": " << cost << std::endl;
	}

	std::cout << " ----------------------------------------- " << std::endl;

	// get the neighbors of graph

	if (graph.find("start") != graph.end())
	{
		for (const auto& neighbor : graph["start"])
		{
			std::cout << neighbor.second << " ";
		}
	}
	std::cout << std::endl;

	// get the weight of edges

	if (graph.find("start") != graph.end() && graph["start"].find("a") != graph["start"].end())
	{
		std::cout << "weight of edge from 'start' to 'a' is: " << graph["start"]["a"] << std::endl;
	}
}
