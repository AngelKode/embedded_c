#include "Graph.h"

Graph::Graph(uint32_t nodeSize, std::vector<std::pair<uint16_t, uint16_t>> graphEdges)
	: adjacencyMatrix(nodeSize, std::vector<uint16_t>(nodeSize, 0)), edges(graphEdges) {  // init list
	// initialize adjacency matrix
	for (const auto& [firstNode, secondNode] : this->edges) {
		// check if the size are inside the boundaries of the 2d-array
		if (!(firstNode >= nodeSize || secondNode >= nodeSize)) {
			// change value to 1 to indicate there is an edge between the 2 nodes
			this->adjacencyMatrix[firstNode][secondNode] = 1;
		}
		else {
			std::cout << "\nThe edge from " << firstNode << " to " << secondNode << " cannot exist\n";
		}
	}
}

uint32_t Graph::getEdgeCount() {
	return static_cast<uint32_t>(this->edges.size());
}

uint32_t Graph::getNodeCount() {
	return static_cast<uint32_t>(this->adjacencyMatrix.size());
}

void Graph::print_adjacency_info() {
	if (!this->edges.empty()) {
		for (std::vector<uint16_t> column : this->adjacencyMatrix) {
			for (uint16_t& row : column) {
				std::cout << " " << row << " ";
			}
			std::cout << '\n';
		}
	}
}

// ------------------------ GraphWeighted -------------------------
GraphWeighted::GraphWeighted(uint32_t nodeSize, std::vector<std::tuple<uint16_t, uint16_t, double>> graphEdges) {
	this->adjacencyMatrix = std::vector<std::vector<double>>(nodeSize, std::vector<double>(nodeSize, static_cast<double>(0)));
	this->edges = graphEdges;
	for (auto& [firstNode, secondNode, weight] : this->edges) {
		// check if the size are inside the boundaries of the 2d-array
		if (!(firstNode >= nodeSize || secondNode >= nodeSize)) {
			this->adjacencyMatrix[firstNode][secondNode] = weight;
		}
		else {
			std::cout << "\nThe edge from " << firstNode << " to " << secondNode << " cannot exist\n";
		}
	}
}

void GraphWeighted::print_adjacency_info() {
	if (!this->edges.empty()) {
		for (std::vector<double> column : this->adjacencyMatrix) {
			for (double& row : column) {
				std::cout << " " << row << " ";
				std::cout << std::setw(10);
			}
			std::cout << "\v";
			std::cout << "\v";
		}
	}
}