//
// Created by xpolas on 1/30/25.
//

#include "TemporalGraph.h"

void TemporalGraph::addTemporalEdge(int u, int v, long timestamp) {
    addEdge(u, v);
    edges.push_back({u, v, timestamp});
}

void TemporalGraph::printTemporalGraphSummary() const {
    if (edges.empty()) {
        std::cout << "The temporal graph is empty!" << std::endl;
        return;
    }

    std::cout << "Temporal Graph Summary:\n";
    std::cout << " - Number of nodes: " << adjacencyList.size() << std::endl;
    std::cout << " - Number of edges: " << edges.size() << std::endl;

    // Find the time range
    long minTime = std::get<2>(edges[0]), maxTime = get<2>(edges[0]);
    for (const auto& edge : edges) {
        minTime = std::min(minTime, std::get<2>(edge));
        maxTime = std::max(maxTime, std::get<2>(edge));
    }

    std::cout << " - Time range: " << minTime << " - " << maxTime << std::endl;
}

