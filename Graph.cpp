//
// Created by xpolas on 1/30/25.
//

#include "Graph.h"
#include <queue>


Graph::Graph() = default;


void Graph::addEdge(int u, int v, double weight) {
    adjacencyList[u].insert(v);
    adjacencyList[v].insert(u);
    edgeWeights[{u, v}] = weight;
    edgeWeights[{v, u}] = weight; //undirected
}

int Graph::numNodes() const {
    return adjacencyList.size();
}

int Graph::numEdges() const {
    long total = 0;
    for (const auto& [node, neighbors] : adjacencyList) {
        total += neighbors.size();
    }
    return total/2;
}

double Graph::density() const {
    int n = numNodes();
    if (n <= 1) return 0.0;
    int e = numEdges();
    return static_cast<double>(e) / (0.5 * n * (n-1)); //density undirected graph
}

double Graph::averageEdgeWeight() const {
    if (edgeWeights.empty()) return 0.0;
    double sum = 0.0;
    for (const auto& [edge, weight] : edgeWeights) {
        sum += weight;
    }
    return sum / edgeWeights.size();
}

int Graph::bfsComponentSize(int start, std::unordered_set<int> &visited) const {
    std::queue<int> q;
    q.push(start);
    visited.insert(start);

    int size = 0;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        size++;

        //run through neighbor
        auto it = adjacencyList.find(current);
        if (it != adjacencyList.end()) {
            for (auto neighbor : it->second) {
                if (!visited.contains(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
    }
    return size;
}

int Graph::largestConnectedComponentSize() const {
    std::unordered_set<int> visited;
    int maxSize = 0;

    for (const auto& [node, _] : adjacencyList) {
        if (!visited.contains(node)) {
            int size = bfsComponentSize(node, visited);
            if (size > maxSize) {
                maxSize = size;
            }
        }
    }
    return maxSize;
}

std::map<int, int> Graph::degreeDistribution() const {
    std::map<int, int> dist;
    for (const auto& [node, neighbors] : adjacencyList) {
        int deg = neighbors.size();
        dist[deg]++;  // Increment frequency for given degree
    }
    return dist;
}

void Graph::printGraphSummary() const
{
    // 1) Basic checks
    int n = numNodes();
    if (n == 0) {
        std::cout << "The graph is empty.\n";
        return;
    }

    // 2) Print basic stats
    int e = numEdges();
    std::cout << "Number of nodes: " << n << std::endl;
    std::cout << "Number of edges: " << e << std::endl;
    std::cout << "Density: " << density() << std::endl;
    std::cout << "Average edge weight: " << averageEdgeWeight() <<std::endl;

    // 3) Largest connected component
    int lcc = largestConnectedComponentSize();
    std::cout << "Largest connected component size: " << lcc << std::endl;

    // 4) Degree distribution
    auto dist = degreeDistribution();
    // If the graph is big, limit the line
    std::cout << "Degree distribution (degree -> count):" << std::endl;
    int counter = 0;
    for (auto& [deg, cnt] : dist) {
        std::cout << "  " << deg << " -> " << cnt << std::endl;
        counter++;
        if (counter >= Constants::limitLinesToPrint) { //limits line to print
            std::cout << "  ... (truncated)\n";
            break;
        }
    }
}

void Graph::saveToFile(const std::string &filename) const {
    std::ofstream outFile(filename);
    for (const auto& [node, neighbors] : adjacencyList) {
        for (const auto& neighbor : neighbors) {
            double weight = edgeWeights.at({node, neighbor}); // Získání váhy hrany
            outFile << node << " " << neighbor << " " << weight << "\n";
        }
    }

    outFile.close();
}

