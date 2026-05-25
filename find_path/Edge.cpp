//
// Created by Malena on 25/05/2026.
//

#include "Edge.h"

Edge::Edge(int destID, int w, std::string line)
    : destinationID(destID), weight(w), lineName(std::move(line)) {

}

int Edge::getDestinationID() const {
    return destinationID;
}

int Edge::getWeight() const {
    return weight;
}

const std::string& Edge::getLine() const {
    return lineName;
}