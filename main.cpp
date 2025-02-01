#include <iostream>

#include "Graph.h"
#include "GraphLoader.h"

int main() {
    std::cout << "Loading static biological network...\n";
    Graph bioGraph = GraphLoader::loadStaticGraph("bio-SC-LC.edges");
    bioGraph.printGraphSummary();
    bioGraph.saveToFile("bio_graph.txt");

    std::cout << "\nLoading temporal social network...\n";
    TemporalGraph socialGraph = GraphLoader::loadTemporalGraph("CollegeMsg.txt");
    socialGraph.printTemporalGraphSummary();
    socialGraph.saveToFile("social_graph.txt");

    return 0;
}

