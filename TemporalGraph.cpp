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



Graph TemporalGraph::getSnapshot(int startTime, int endTime) const {
    Graph snapshot;
    for (const auto& edge : edges) {
        if (std::get<3>(edge) >= startTime && std::get<3>(edge) <= endTime) {
            int u = std::get<0>(edge);
            int v = std::get<1>(edge);
            double weight = std::get<2>(edge); // weight
            snapshot.addEdge(u, v, weight);
        }
    }
    return snapshot;
}

std::vector<Graph> TemporalGraph::generateSnapshots(int intervalSize) const {
    std::vector<Graph> snapshots;
    int startTime = timeRangeStart;
    int endTime = timeRangeEnd;

    for (int t = startTime; t < endTime; t += intervalSize) {
        Graph snapshot = getSnapshot(t, t + intervalSize);
        snapshots.push_back(snapshot);
    }
    return snapshots;
}

void TemporalGraph::printTemporalGraphSummary() const {
    std::cout << "Temporal Graph Summary:\n";
    std::cout << " - Number of nodes: " << numNodes() << "\n";
    std::cout << " - Number of edges: " << numEdges() << "\n";
    std::cout << " - Time range: " << timeRangeStart << " - " << timeRangeEnd << "\n";


}

void TemporalGraph::printSnapshotSummary() const {
    if (!snapshots.empty()) {
        std::cout << " - Number of snapshots: " << snapshots.size() << "\n";
        int count = 0;
        for (const auto& snapshot : snapshots) {
            std::cout << "   * Time " << snapshot.first << " -> "
                      << snapshot.second.numNodes() << " nodes, "
                      << snapshot.second.numEdges() << " edges\n";
            if (++count >= Constants::limitNumSnaps) { // Limit the number of printed snapshots
                std::cout << "   ... (truncated)\n";
                break;
            }
        }
    }
}



