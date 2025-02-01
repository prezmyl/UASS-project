//
// Created by xpolas on 1/30/25.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>
#include <utility>

struct pair_hash {
    template <typename T1, typename T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        return std::hash<T1>{}(p.first) ^ (std::hash<T2>{}(p.second) << 1);
    }
};

class Graph {
protected:
    std::unordered_map<int, std::set<int>> adjacencyList; //undirected
    std::unordered_map<std::pair<int, int>, double, pair_hash> edgeWeights;

public:
    Graph();
    void addEdge(int u, int v, double weight = 1.0);
    void printGraphSummary() const;
    void saveToFile(const std::string &filename) const;

};


#endif //GRAPH_H
