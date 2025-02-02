//
// Created by xpolas on 1/30/25.
//

#include "TemporalGraph.h"

#include <limits.h>

TemporalGraph::TemporalGraph() : timeRangeStart(LONG_MAX), timeRangeEnd(LONG_MIN){}


void TemporalGraph::addTemporalEdge(int u, int v, double weight, long timestamp) {
    // Pokud už hrana existuje, přičteme novou délku hovoru a zvýšíme počet hovorů
    if (adjacencyList[u].count(v)) {
        adjacencyList[u][v].first += weight;  // Sčítání délky hovorů
        adjacencyList[u][v].second += 1;      // Počet hovorů
        adjacencyList[v][u].first += weight;
        adjacencyList[v][u].second += 1;
    } else {
        adjacencyList[u][v] = {weight, 1};  // První hovor mezi těmito uzly
        adjacencyList[v][u] = {weight, 1};
    }

    timeRangeStart = std::min(timeRangeStart, timestamp);
    timeRangeEnd = std::max(timeRangeEnd, timestamp);
}


int TemporalGraph::numEdges() const {
    return edges.size(); // Počítáme skutečný počet uložených hran
}





TemporalGraph TemporalGraph::getSnapshot(long start, long end) const {
    TemporalGraph snapshot;

    for (const auto& edge : edges) {
        long timestamp = std::get<3>(edge);
        if (timestamp >= start && timestamp < end) {
            int u = std::get<0>(edge);
            int v = std::get<1>(edge);
            double weight = std::get<2>(edge);
            snapshot.addTemporalEdge(u, v, weight, timestamp);
        }
    }
    std::cout << "📸 Snapshotting: " << start << " - " << end
          << " | Total edges: " << snapshot.edges.size() << std::endl;

    return snapshot;
}



std::vector<TemporalGraph> TemporalGraph::generateSnapshots(long interval) const {
    std::vector<TemporalGraph> snapshots;
    int totalEdgesInAllSnapshots = 0;
    for (long start = timeRangeStart; start < timeRangeEnd; start += interval) {
        long end = start + interval;
        snapshots.push_back(getSnapshot(start, end));
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

void TemporalGraph::saveSnapshotsToFile(const std::string &filename, long snapshotInterval) const {
    std::ofstream outFile(filename);
    for (long start = timeRangeStart; start < timeRangeEnd; start += snapshotInterval) {
        long end = start + snapshotInterval;
        TemporalGraph snapshot = getSnapshot(start, end);

        for (const auto& edge : snapshot.edges) {
            outFile << std::get<0>(edge) << " "
                    << std::get<1>(edge) << " "
                    << std::get<2>(edge) << " "
                    << std::get<3>(edge) << "\n";
        }
    }
    outFile.close();
    std::cout << "✅ Snapshots saved to " << filename << std::endl;
}





