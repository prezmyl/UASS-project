//
// Created by xpolas on 1/30/25.
//

#include "Graph.h"


Graph::Graph() = default;


void Graph::addEdge(int u, int v, double weight) {
    adjacencyList[u].insert(v);
    adjacencyList[v].insert(u);
    edgeWeights[{u, v}] = weight;
    edgeWeights[{v, u}] = weight;
}

void Graph::printGraphSummary() const {
    if (adjacencyList.empty()) {
        std::cout << "The graph is empty!" << std::endl;
        return;
    }

    int numEdges = 0;
    for (const auto& node : adjacencyList) {
        numEdges += node.second.size();
    }
    numEdges /= 2; // Since the graph is undirected

    std::cout << "Static Graph Summary:\n";
    std::cout << " - Number of nodes: " << adjacencyList.size() << std::endl;
    std::cout << " - Number of edges: " << numEdges << std::endl;
}

void Graph::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    for (const auto& node : adjacencyList) {
        for (int neighbor : node.second) {
            file << node.first << " " << neighbor << "\n";
        }
    }
    file.close();
    std::cout << "Graph saved to file: " << filename << std::endl;
}

