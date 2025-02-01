#include "GraphLoader.h"
#include "TemporalGraph.h"
#include <iostream>

int main() {
    std::cout << "Loading static biological network...\n";
    Graph bioGraph = GraphLoader::loadStaticGraph("bio-SC-LC.edges");
    bioGraph.printGraphSummary();
    bioGraph.saveToFile("bio_graph.txt");

    std::cout << "\nLoading temporal social network...\n";
    TemporalGraph socialGraph = GraphLoader::loadTemporalGraph("CollegeMsg.txt");

    // Analyze the entire temporal graph first
    socialGraph.printTemporalGraphSummary();
    socialGraph.saveToFile("social_graph.txt");

    // Now create snapshots and analyze them separately
    std::cout << "\nCreating temporal snapshots...\n";
    socialGraph.createSnapshots(3600 * 24 * 30); // Monthly snapshots
    socialGraph.printTemporalGraphSummary();

    return 0;
}
