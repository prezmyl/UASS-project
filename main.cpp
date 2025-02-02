#include "GraphLoader.h"
#include "TemporalGraph.h"
#include <iostream>

/*
 *podivej se jak s tim pracuje gelphi
 *jak deli intervaly, co ty data znamenaji, co delat kdyz stejne hrany jiny timestep
 *by moha byt vaha, ale vaha je tam jako porametr, tak jak?
 **/




int main() {
    std::ofstream bioFile("bio_metrics.txt");
    std::ofstream temporalFile("temporal_metrics.txt", std::ios::app);

    Graph bioGraph = GraphLoader::loadStaticGraph("bio-SC-LC.edges");
    bioGraph.analyzeGraph("Biological Network", std::cout, bioFile);
    bioGraph.saveToFile("bio_graph.txt");
    bioFile.close();

    TemporalGraph temporalGraph = GraphLoader::loadTemporalGraph("ia-reality-call.edges");
    temporalGraph.analyzeTemporalProperties(std::cout, temporalFile);
    temporalGraph.analyzeGraph("Temporal Network", std::cout, temporalFile);
    temporalGraph.analyzeSnapshots("snapshots", Constants::snapInterval);
    temporalGraph.saveToFile("temporal_graph.txt");
    temporalFile.close();

    return 0;
}

