#pragma once
#ifndef Graph_HEADER
#define Graph_HEADER

#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <iomanip>

// TODO : optimize adjacency matrix into a simple array and each value goes at index (nodeSize*i)+j
// TODO : change adjacency matrix to have pairs of <target, weight>
class Graph {
private:
	std::vector<std::vector<uint16_t>> adjacencyMatrix;
	std::vector<std::pair<uint16_t, uint16_t>> edges;
public:
	explicit Graph() : Graph(0, { {} }) {};
	explicit Graph(uint32_t nodeSize, std::vector<std::pair<uint16_t, uint16_t>> graphEdges);
	bool operator==(const Graph& other) const = default;
	uint32_t getEdgeCount();
	uint32_t getNodeCount();
	void print_adjacency_info();
};

class GraphWeighted {
private:
	std::vector<std::vector<double>> adjacencyMatrix;
	std::vector<std::tuple<uint16_t, uint16_t, double>> edges;
public:
	explicit GraphWeighted() : GraphWeighted(0, { {} }) {};
	explicit GraphWeighted(uint32_t nodeSize, std::vector<std::tuple<uint16_t, uint16_t, double>> graphEdges);
	bool operator==(const GraphWeighted& other) const = default;
	//uint32_t getEdgeCount();
	//uint32_t getNodeCount();
	void print_adjacency_info();
};

#endif // Graph_HEADER
