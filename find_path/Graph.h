//
// Created by Malena on 25/05/2026.
//

#ifndef FIND_PATH_GRAPH_H
#define FIND_PATH_GRAPH_H

#include <vector>
#include "Station.h"


class Graph {
public:
    Graph();
    bool loadFromFile(const std::string& file);
    void printGraph() const;
    void findShortestPath(const std::string& startName, const std::string& destName);

private:
    std::vector<Station> stations;

    int getOrCreateID(std::string& name);
};


#endif //FIND_PATH_GRAPH_H