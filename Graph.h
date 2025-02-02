//
// Created by xpolas on 1/30/25.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <utility>
#include "Constants.h"

struct pair_hash {
    template <typename T1, typename T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        return std::hash<T1>{}(p.first) ^ (std::hash<T2>{}(p.second) << 1);
    }
};

class Graph {
protected:
    // adjacencyList: uchovává { sousední uzel -> { celková váha, počet opakování } }
    std::unordered_map<int, std::unordered_map<int, std::pair<double, int>>> adjacencyList;

public:
    Graph();
    void addEdge(int u, int v, double weight);
    int numNodes() const;
    int numEdges() const;
    double density() const;
    double averageEdgeWeight() const;
    int bfsComponentSize(int start, std::unordered_set<int> &visited) const;
    int largestConnectedComponentSize() const;
    std::map<int, int> degreeDistribution() const;
    void printGraphSummary() const;
    void saveToFile(const std::string &filename) const;
    void convertFromTemporalGraph(const std::vector<std::tuple<int, int, double, long>>& edges);
    const std::unordered_map<int, std::unordered_map<int, std::pair<double, int>>>& getAdjacencyList() const {
        return adjacencyList;
    }



};


#endif //GRAPH_H
