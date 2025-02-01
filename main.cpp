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

    // Dividing temporal graph into snapshots
    std::cout << "\nGenerating snapshots...\n";
   // socialGraph.createSnapshots(10);

    // Analyzing snapshots
    int count = 0;
    for (const auto& snapshot : socialGraph.generateSnapshots(3600 * 24 * 30)) {
        std::cout << "\nSnapshot " << count + 1 << ":\n";
        snapshot.printGraphSummary();
        count++;
    }

    return 0;
}
