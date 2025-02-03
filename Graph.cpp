//
// Created by xpolas on 1/30/25.
//

#include "Graph.h"

#include <algorithm>
#include <queue>


Graph::Graph() = default;


void Graph::addEdge(int u, int v, double weight) {
    if (adjacencyList[u].count(v)) {
        adjacencyList[u][v].first += weight;  // Sčítáme váhu (délku hovorů)
        adjacencyList[u][v].second += 1;      // Počet opakování hrany (počet hovorů)
        adjacencyList[v][u].first += weight;
        adjacencyList[v][u].second += 1;
    } else {
        adjacencyList[u][v] = {weight, 1};
        adjacencyList[v][u] = {weight, 1};
    }
}

int Graph::numNodes() const {
    return adjacencyList.size();
}

int Graph::numEdges() const {
    int count = 0;
    for (const auto &node : adjacencyList) {
        count += node.second.size();
    }
    return count / 2;  // Kvůli neorientovanému grafu
}

double Graph::density() const {
    int n = numNodes();
    if (n <= 1) return 0.0;
    int e = numEdges();
    return static_cast<double>(e) / (0.5 * n * (n-1)); //density undirected graph
}

double Graph::averageEdgeWeight() const {
    if (adjacencyList.empty()) return 0.0;

    double sum = 0.0;
    int count = 0;

    for (const auto& [node, neighbors] : adjacencyList) {
        for (const auto& [neighbor, data] : neighbors) {
            if (node < neighbor) { // Aby se hrany nepočítaly dvakrát
                sum += data.first;
                count++;
            }
        }
    }

    return (count > 0) ? sum / count : 0.0;
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

        auto it = adjacencyList.find(current);
        if (it != adjacencyList.end()) {
            for (const auto& [neighbor, _] : it->second) {  // Použití iterátoru pro adjacencyList
                if (visited.find(neighbor) == visited.end()) {
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
        if (visited.find(node) == visited.end()) {  // Opraveno, `contains()` není v `unordered_set`
            int size = bfsComponentSize(node, visited);
            maxSize = std::max(maxSize, size);
        }
    }
    return maxSize;
}


std::map<int, int> Graph::degreeDistribution() const {
    std::map<int, int> dist;
    for (const auto& [node, neighbors] : adjacencyList) {
        int deg = neighbors.size();
        dist[deg]++;  // Zvýšíme frekvenci daného stupně
    }
    return dist;
}


double Graph::averageDegree() const {
    if (adjacencyList.empty()) return 0.0;
    double totalDegree = 0;
    for (const auto& [node, neighbors] : adjacencyList) {
        totalDegree += neighbors.size();
    }
    return totalDegree / adjacencyList.size();
}

double Graph::clusteringCoefficient() const {
    if (adjacencyList.empty()) return 0.0;

    double totalClustering = 0.0;
    for (const auto& [node, neighbors] : adjacencyList) {
        int degree = neighbors.size();
        if (degree < 2) continue;

        int triangles = 0;
        for (const auto& [neighbor1, _] : neighbors) {
            for (const auto& [neighbor2, _] : neighbors) {
                if (neighbor1 != neighbor2 && adjacencyList.at(neighbor1).count(neighbor2)) {
                    triangles++;
                }
            }
        }
        totalClustering += (double)triangles / (degree * (degree - 1));
    }
    return totalClustering / adjacencyList.size();
}

int Graph::triangleCount() const {
    int count = 0;
    for (const auto& [node, neighbors] : adjacencyList) {
        for (const auto& [neighbor1, _] : neighbors) {
            for (const auto& [neighbor2, _] : neighbors) {
                if (neighbor1 != neighbor2 && adjacencyList.at(neighbor1).count(neighbor2)) {
                    count++;
                }
            }
        }
    }
    return count / 3; // Každý trojúhelník byl spočítán třikrát
}

int Graph::mostActiveNode() const {
    int maxNode = -1;
    int maxDegree = 0;
    for (const auto& [node, neighbors] : adjacencyList) {
        if (neighbors.size() > maxDegree) {
            maxDegree = neighbors.size();
            maxNode = node;
        }
    }
    return maxNode;
}

std::vector<int> Graph::findTopHubs(int topN) const {
    std::vector<std::pair<int, int>> degreeList;

    // Vytvoření seznamu (uzel, stupeň)
    for (const auto& [node, neighbors] : adjacencyList) {
        degreeList.emplace_back(node, neighbors.size());
    }

    // Seřadíme podle stupně sestupně
    std::sort(degreeList.begin(), degreeList.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // Vybereme prvních N hubů
    std::vector<int> topHubs;
    for (int i = 0; i < std::min(topN, static_cast<int>(degreeList.size())); ++i) {
        topHubs.push_back(degreeList[i].first);
    }

    return topHubs;
}


void Graph::analyzeGraph(const std::string& name, std::ostream& out1, std::ostream& out2, const std::string& filename) const {
    Utils::writeOutput(out1, out2, "📊 " + name + " Summary:");
    Utils::writeOutput(out1, out2, " - Nodes: " + std::to_string(numNodes()));
    Utils::writeOutput(out1, out2, " - Edges: " + std::to_string(numEdges()));
    Utils::writeOutput(out1, out2, " - Density: " + std::to_string(density()));
    Utils::writeOutput(out1, out2, " - Avg Degree: " + std::to_string(averageDegree()));
    Utils::writeOutput(out1, out2, " - Clustering: " + std::to_string(clusteringCoefficient()));
    Utils::writeOutput(out1, out2, " - Triangles: " + std::to_string(triangleCount()));
    Utils::writeOutput(out1, out2, " - Most active node: " + std::to_string(mostActiveNode()));

    std::vector<int> topHubs = findTopHubs(20);
    Utils::writeOutput(out1, out2, " - Top 20 Hubs:");
    for (int hub : topHubs) {
        Utils::writeOutput(out1, out2, "   - Node " + std::to_string(hub) + " with degree " + std::to_string(adjacencyList.at(hub).size()));
    }

    Utils::writeOutput(out1, out2, "Degree distribution:");
    for (const auto& [degree, count] : degreeDistribution()) {
        Utils::writeOutput(out1, out2, "  " + std::to_string(degree) + " -> " + std::to_string(count));
    }

    saveNodeDegrees(filename + "_node_degrees.txt");
    Utils::writeOutput(out1, out2, "----------------------------------");
}

void Graph::saveNodeDegrees(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "❌ Error: Unable to open file " << filename << std::endl;
        return;
    }

    outFile << "# Node Degree List\n";
    for (const auto& [node, neighbors] : adjacencyList) {
        outFile << node << " " << neighbors.size() << "\n";
    }

    outFile.close();
    std::cout << "✅ Node degrees saved to " << filename << std::endl;
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
    if (!outFile.is_open()) {
        std::cerr << "❌ Error: Unable to open file " << filename << std::endl;
        return;
    }

    for (const auto& [node, neighbors] : adjacencyList) {
        for (const auto& [neighbor, data] : neighbors) {
            double weight = data.first; // Celková délka hovorů
            int callCount = data.second; // Počet hovorů
            outFile << node << " " << neighbor << " " << weight << " " << callCount << "\n";
        }
    }

    outFile.close();
    std::cout << "✅ Graph successfully saved to " << filename << std::endl;
}



