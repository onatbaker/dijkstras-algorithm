#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>

struct Graph
{
	std::unordered_map<std::string, std::unordered_map<std::string, double>> graph;
	std::unordered_map<std::string, double> costs;
	std::unordered_map<std::string, std::string> parents;
};

Graph makeGraph(Graph& graph)
{
	double inf = std::numeric_limits<double>::infinity();

	graph.graph["start"]["a"] = 6;
	graph.graph["start"]["b"] = 2;

	graph.graph["a"]["fin"] = 1;

	graph.graph["b"]["a"] = 3;
	graph.graph["b"]["fin"] = 5;

	graph.costs["a"] = 6;
	graph.costs["b"] = 2;
	graph.costs["fin"] = inf;

	graph.parents["a"] = "start";
	graph.parents["b"] = "start";
	graph.parents["fin"] = "";

	return graph;
}

std::string findLowestCostNode(std::unordered_map<std::string, double>& costs, const std::vector<std::string>& processed)
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

void Dijkstra(Graph& graph)
{
	std::vector<std::string> processed;
	std::string node = findLowestCostNode(graph.costs, processed);
	while (!node.empty())
	{
		double cost = graph.costs[node];
		const auto& neighbors = graph.graph[node];

		for (const auto& pair : neighbors)
		{
			const auto& neighbor = pair.first;
			double weight = pair.second;
			double newCost = cost + weight;

			if (graph.costs[neighbor] > newCost)
			{
				graph.costs[neighbor] = newCost;
				graph.parents[neighbor] = node;
			}
		}
		processed.push_back(node);
		node = findLowestCostNode(graph.costs, processed);
	}
}

void printNeighbor(Graph& graph)
{
	if (graph.graph.find("start") != graph.graph.end())
	{
		for (const auto& neighbor : graph.graph["start"])
		{
			std::cout << neighbor.second << " ";
		}
	}
	std::cout << std::endl;
}

void printWeightOfEdges(Graph& graph)
{
	if (graph.graph.find("start") != graph.graph.end() && graph.graph["start"].find("a") != graph.graph["start"].end())
	{
		std::cout << "weight of edge from 'start' to 'a' is: " << graph.graph["start"]["a"] << std::endl;
	}
}
