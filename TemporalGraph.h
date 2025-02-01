//
// Created by xpolas on 1/30/25.
//

#ifndef TEMPORALGRAPH_H
#define TEMPORALGRAPH_H

#include <map>

#include "Graph.h"

class TemporalGraph : public Graph {
private:
    std::vector<std::tuple<int, int, long>> edges; // node1, node2, timestep
    std::map<int, Graph> snapshots;
    long timeRangeStart, timeRangeEnd;

public:
    TemporalGraph();
    void addTemporalEdge(int u, int v, long timestamp);
    void printTemporalGraphSummary() const;
    void createSnapshots(int interval);
    TemporalGraph getSnapshot(int startTime, int endTime) const;
};




#endif //TEMPORALGRAPH_H
