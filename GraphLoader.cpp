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
    int count = 0;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<std::string> tokens;
        std::string token;

        // Správné rozdělení řádku podle čárek
        while (std::getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 4) {
            std::cerr << "⚠ Warning: Skipping malformed line: " << line << std::endl;
            continue;
        }

        int u = std::stoi(tokens[0]);
        int v = std::stoi(tokens[1]);
        long timestamp = std::stol(tokens[2]);
        double weight = std::stod(tokens[3]);

        // Přidání hrany do temporálního grafu
        graph.addTemporalEdge(u, v, weight, timestamp);
        count++;
    }

    file.close();
    std::cout << "✅ Loaded " << count << " edges into temporal graph." << std::endl;
    return graph;
}





