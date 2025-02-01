//
// Created by xpolas on 1/30/25.
//

#ifndef TEMPORALGRAPH_H
#define TEMPORALGRAPH_H

#include <map>

#include "Graph.h"

class TemporalGraph : public Graph {
private:
    std::vector<std::tuple<int, int, double, long>> edges; // node1, node2, timestep
    std::map<int, Graph> snapshots; //mapping snaposthos to subgraphs
    long timeRangeStart, timeRangeEnd; //min and max timestep in database

public:
    TemporalGraph();
    void addTemporalEdge(int u, int v, double weight, long timestamp);
    Graph getSnapshot(int startTime, int endTime) const;
    void printTemporalGraphSummary() const;
    void printSnapshotSummary() const;
    std::vector<Graph> generateSnapshots(int intervalSize) const;
};




#endif //TEMPORALGRAPH_H
