//
// Created by xpolas on 1/30/25.
//

#ifndef GRAPHLOADER_H
#define GRAPHLOADER_H
#include "Graph.h"
#include "TemporalGraph.h"


class GraphLoader {
public:
    static Graph loadStaticGraph(const std::string& filename);

    static TemporalGraph loadTemporalGraph(const std::string& filename);
};




#endif //GRAPHLOADER_H
