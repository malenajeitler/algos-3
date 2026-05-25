//
// Created by Malena on 25/05/2026.
//

#include "Station.h"

Station::Station(int stationID, std::string stationName)
    : id(stationID), name(std::move(stationName)) {

}

void Station::addEdge(int destinationID, int weight, const std::string& lineName) {
    adjacencies.emplace_back(destinationID, weight, lineName);
}

int Station::getID() const {
    return id;
}

const std::string& Station::getName() const {
    return name;
}

const std::vector<Edge>& Station::getAdjacencies() const {
    return adjacencies;
}