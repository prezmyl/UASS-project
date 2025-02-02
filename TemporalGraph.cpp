//
// Created by xpolas on 1/30/25.
//

#include "TemporalGraph.h"

#include <limits.h>

TemporalGraph::TemporalGraph() : timeRangeStart(LONG_MAX), timeRangeEnd(LONG_MIN){}


void TemporalGraph::addTemporalEdge(int u, int v, double weight, long timestamp) {
    edges.emplace_back(u, v, weight, timestamp);
    addEdge(u, v, weight);
    timeRangeStart = std::min(timeRangeStart, timestamp);
    timeRangeEnd = std::max(timeRangeEnd, timestamp);
}


int TemporalGraph::numEdges() const {
    return edges.size(); // Počítáme skutečný počet uložených hran
}


Graph TemporalGraph::convertToStaticGraph() const {
    Graph staticGraph;
    for (const auto& edge : edges) {
        int u = std::get<0>(edge);
        int v = std::get<1>(edge);
        double weight = std::get<2>(edge);
        staticGraph.addEdge(u, v, weight);
    }
    return staticGraph;
}


Graph TemporalGraph::getSnapshot(long start, long end) const {
    Graph snapshot;

    for (const auto& edge : edges) {
        long timestamp = std::get<3>(edge);
        if (timestamp >= start && timestamp < end) {
            int u = std::get<0>(edge);
            int v = std::get<1>(edge);
            double weight = std::get<2>(edge);
            snapshot.addEdge(u, v, weight);
        }
    }

    return snapshot;
}


std::vector<Graph> TemporalGraph::generateSnapshots(long interval, const std::string& outputPrefix = "") const {
    std::vector<Graph> snapshots;

    for (long start = timeRangeStart; start < timeRangeEnd; start += interval) {
        long end = start + interval;
        Graph snapshot = getSnapshot(start, end);
        snapshots.push_back(snapshot);

        if (!outputPrefix.empty()) { // Pokud je zadán prefix, rovnou ukládáme snapshoty
            std::string filename = outputPrefix + "_snapshot_" + std::to_string(start) + "_" + std::to_string(end) + ".txt";
            saveSnapshotToFile(snapshot, filename, start, end);
        }
    }

    return snapshots;
}





void TemporalGraph::printTemporalGraphSummary() const {
    std::cout << "Temporal Graph Summary:\n";
    std::cout << " - Number of nodes: " << numNodes() << "\n";
    std::cout << " - Number of edges: " << numEdges() << "\n";
    std::cout << " - Time range: " << timeRangeStart << " - " << timeRangeEnd << "\n";

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

void TemporalGraph::saveToFile(const std::string &filename) const {
    std::ofstream outFile(filename);
    for (const auto& edge : edges) {
        int u = std::get<0>(edge);
        int v = std::get<1>(edge);
        double weight = std::get<2>(edge);
        long timestamp = std::get<3>(edge);
        outFile << u << " " << v << " " << timestamp << " " << weight << "\n"; // ✅ Opraveno
    }
    outFile.close();
}

void TemporalGraph::saveSnapshotToFile(const Graph &snapshot, const std::string &filename, long start, long end) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "❌ Error: Cannot open file " << filename << " for writing." << std::endl;
        return;
    }

    outFile << "# Snapshot from " << start << " to " << end << "\n";
    for (const auto& [node, neighbors] : snapshot.getAdjacencyList()) {
        for (const auto& [neighbor, weight] : neighbors) {
            outFile << node << " " << neighbor << " " << weight.first << " " << weight.second << "\n";
        }
    }
    outFile.close();
    std::cout << "✅ Snapshot saved: " << filename << std::endl;
}









