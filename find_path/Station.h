//
// Created by Malena on 25/05/2026.
//

#ifndef FIND_PATH_STATION_H
#define FIND_PATH_STATION_H

#include <string>
#include <vector>
#include "Edge.h"


class Station {
public:
    Station(int stationID, std::string stationName);

    void addEdge(int destinationID, int weight, const std::string& lineName);

    int getID() const;
    const std::string& getName() const;
    const std::vector<Edge>& getAdjacencies() const;

private:
    int id;
    std::string name;
    std::vector<Edge> adjacencies;
};


#endif //FIND_PATH_STATION_H