//
// Created by xpolas on 1/30/25.
//

#include "TemporalGraph.h"

#include <limits.h>

TemporalGraph::TemporalGraph() : timeRangeStart(LONG_MAX), timeRangeEnd(LONG_MIN){}


void TemporalGraph::addTemporalEdge(int u, int v, long timestamp) {
    addEdge(u, v);
    edges.push_back({u, v, timestamp});
    addEdge(v, u); //for the static graph

    timeRangeStart = std::min(timeRangeStart, timestamp);
    timeRangeEnd = std::max(timeRangeEnd, timestamp);
}


void TemporalGraph::createSnapshots(int interval) {
    int currentTime = timeRangeStart;
    while (currentTime <= timeRangeEnd) {
        snapshots[currentTime] = getSnapshot(currentTime, currentTime + interval);
        currentTime += interval;
    }
}

TemporalGraph TemporalGraph::getSnapshot(int startTime, int endTime) const {
    TemporalGraph snapshot;
    for (const auto& edge : edges) {
        if (std::get<2>(edge) >= startTime && std::get<2>(edge) <= endTime) {
            snapshot.addTemporalEdge(std::get<0>(edge), std::get<1>(edge), std::get<2>(edge));
        }
    }
    return snapshot;
}


void TemporalGraph::printTemporalGraphSummary() const {
    std::cout << "Temporal Graph Summary:\n";
    std::cout << " - Number of nodes: " << adjacencyList.size() << "\n";
    std::cout << " - Number of edges: " << edges.size() << "\n";
    std::cout << " - Time range: " << timeRangeStart << " - " << timeRangeEnd << "\n";

    // Print snapshots if available
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


