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

TemporalGraph GraphLoader::loadTemporalGraph(const std::string &filename) {
    TemporalGraph graph;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "❌ Error: Could not open file " << filename << std::endl;
        return graph;
    }

    std::string line;
    int edgeCount = 0;
    std::set<int> uniqueNodes;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() != 4) {
            std::cerr << "⚠️ Skipping invalid line: " << line << std::endl;
            continue;
        }

        try {
            int u = std::stoi(tokens[0]);
            int v = std::stoi(tokens[1]);
            long timestamp = std::stol(tokens[2]);
            int weight = std::stoi(tokens[3]);

            // Ukládáme všechny hrany včetně těch s různým časovým údajem
            graph.addTemporalEdge(u, v, weight, timestamp);
            edgeCount++;

            uniqueNodes.insert(u);
            uniqueNodes.insert(v);
        } catch (const std::exception &e) {
            std::cerr << "❌ Parsing error on line: " << line << " -> " << e.what() << std::endl;
        }
    }

    std::cout << "✅ Total edges attempted to add: " << edgeCount << std::endl;
    std::cout << "✅ Total unique nodes added: " << uniqueNodes.size() << std::endl;

    return graph;
}




