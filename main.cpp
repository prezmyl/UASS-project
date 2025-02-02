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
    std::ofstream temporalFile("temporal_metrics.txt");

    Graph bioGraph = GraphLoader::loadStaticGraph("bio-SC-LC.edges");
    bioGraph.analyzeGraph("Biological Network", std::cout, bioFile);

    TemporalGraph temporalGraph = GraphLoader::loadTemporalGraph("ia-reality-call.edges");
    temporalGraph.analyzeTemporalProperties(std::cout, temporalFile);
    temporalGraph.analyzeSnapshots("snapshots", Constants::snapInterval);

    return 0;
}

