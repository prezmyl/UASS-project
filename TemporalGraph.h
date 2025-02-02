//
// Created by xpolas on 1/30/25.
//

#ifndef TEMPORALGRAPH_H
#define TEMPORALGRAPH_H

#include <map>

#include "Graph.h"

struct EdgeKey {
    int u, v;
    long timestamp;

    bool operator==(const EdgeKey &other) const {
        return u == other.u && v == other.v && timestamp == other.timestamp;
    }
};

namespace std {
    template <>
    struct hash<EdgeKey> {
        size_t operator()(const EdgeKey &key) const {
            return hash<int>()(key.u) ^ hash<int>()(key.v) ^ hash<long>()(key.timestamp);
        }
    };
}

class TemporalGraph : public Graph {
private:
    std::unordered_set<EdgeKey> existingEdges;
    std::vector<std::tuple<int, int, double, long>> edges; // node1, node2, timestep
    std::map<int, Graph> snapshots; //mapping snaposthos to subgraphs
    long timeRangeStart, timeRangeEnd; //min and max timestep in database

public:
    TemporalGraph();
    void addTemporalEdge(int u, int v, double weight, long timestamp);
    int numEdges() const;

    TemporalGraph getSnapshot(long start, long end) const;
    std::vector<TemporalGraph> generateSnapshots(long interval) const;

    void printTemporalGraphSummary() const;
    void saveToFile(const std::string &filename) const;
    void saveSnapshotsToFile(const std::string &filename, long snapshotInterval) const;
};




#endif //TEMPORALGRAPH_H
