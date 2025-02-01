//
// Created by xpolas on 1/30/25.
//

#include "GraphLoader.h"

Graph GraphLoader::loadStaticGraph(const std::string &filename)  {
    Graph graph;
    std::ifstream file(filename);
    std::string line;
    int count = 0;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int u, v;
        double weight = 1.0;
        if (!(iss >> u >> v >> weight)) {
            continue; // skip wrong lines
        }
        graph.addEdge(u, v, weight);
        count++;
    }
    std::cout << count << " edges loaded" << std::endl;
    return graph;
}

TemporalGraph GraphLoader::loadTemporalGraph(const std::string &filename)  {
    TemporalGraph graph;
    std::ifstream file(filename);
    std::string line;
    int count = 0;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int u, v;
        long timestamp;
        double weight = 1.0;
        if (!(iss >> u >> v >> timestamp)) {
            continue; // skip wrong line
        }
        graph.addTemporalEdge(u, v, weight,timestamp);
        count++;
    }
    std::cout << count << " edges loaded" << std::endl;
    return graph;
}
