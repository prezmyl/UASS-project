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
    std::ofstream bioMetricsFile("bio_metrics.txt");
    std::ofstream temporalMetricsFile("temporal_metrics.txt");

    Graph bioGraph = GraphLoader::loadStaticGraph("bio-SC-LC.edges");

    bioGraph.analyzeGraph("Biological Network", std::cout, bioMetricsFile);
    bioGraph.saveToFile("bio_graph.txt");
    bioGraph.saveNodeDegrees("bio_graph_node_degrees.txt");
    bioMetricsFile.close();
    bioFile.close();

    TemporalGraph temporalGraph = GraphLoader::loadTemporalGraph("ia-reality-call.edges");
    temporalGraph.analyzeTemporalProperties(std::cout, temporalFile);
    temporalGraph.analyzeGraph("Temporal Network", std::cout, temporalMetricsFile);
    temporalGraph.analyzeSnapshots("snapshots", Constants::snapInterval);
    temporalGraph.saveToFile("temporal_graph.txt");
    temporalGraph.saveNodeDegrees("temporal_graph_node_degrees.txt");
    temporalMetricsFile.close();
    temporalFile.close();

    return 0;
}

