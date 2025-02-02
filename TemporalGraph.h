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
    std::vector<std::tuple<int, int, double, long>> edges;
    long timeRangeStart;
    long timeRangeEnd;

public:
    TemporalGraph();
    void addTemporalEdge(int u, int v, double weight, long timestamp);
    int numEdges() const;

    double averageCallDuration() const;
    double averageActivity() const;


    Graph convertToStaticGraph() const;
    Graph getSnapshot(long start, long end) const;
    std::vector<Graph> generateSnapshots(long interval, const std::string &outputPrefix) const;

    void printTemporalGraphSummary() const;

    void analyzeTemporalProperties(std::ostream &out1, std::ostream &out2) const;

    void analyzeSnapshots(const std::string &dir, long snapshotInterval) const;

    void saveToFile(const std::string &filename) const;
    void saveSnapshotToFile(const Graph &snapshot, const std::string &filename, long start, long end) const;


};




#endif //TEMPORALGRAPH_H
