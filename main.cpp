#include "GraphLoader.h"
#include "TemporalGraph.h"
#include <iostream>

/*
 *podivej se jak s tim pracuje gelphi
 *jak deli intervaly, co ty data znamenaji, co delat kdyz stejne hrany jiny timestep
 *by moha byt vaha, ale vaha je tam jako porametr, tak jak?
 **/

int main() {
    std::cout << "Loading static biological network...\n";
    Graph bioGraph = GraphLoader::loadStaticGraph("bio-SC-LC.edges");
    bioGraph.printGraphSummary();
    bioGraph.saveToFile("bio_graph.txt");

    std::cout << "\nLoading temporal network...\n";
    TemporalGraph temporalGraph = GraphLoader::loadTemporalGraph("ia-reality-call.edges");


    // Analyze the entire temporal graph first
    temporalGraph.printTemporalGraphSummary();
    temporalGraph.saveToFile("temporal_graph.txt");

    // Dividing temporal graph into snapshots
    std::cout << "\nGenerating snapshots...\n";
    auto snapshots = temporalGraph.generateSnapshots(Constants::snapInterval, "temporal_graph");


    for (size_t i = 0; i < snapshots.size(); i++) {
        std::cout << "\nSnapshot " << i + 1 << ":\n";
        snapshots[i].printGraphSummary();
    }


    return 0;
}
