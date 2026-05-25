//
// Created by Malena on 25/05/2026.
//

#include "Graph.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>

Graph::Graph() {

}

int Graph::getOrCreateID(std::string& name) {
    for (int i = 0; i < stations.size(); i++) {
        if (stations[i].getName() == name) {
            return i;
        }
    }

    int newID = stations.size();
    stations.emplace_back(newID, name);
    return newID;
}

bool Graph::loadFromFile(const std::string& file) {
    std::ifstream fileStream(file);
    if (!fileStream.is_open()) {
        std::cout << "File " << file << " could not be opened." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(fileStream, line)) {
        if (line.empty()) {
            continue;
        }

        std::stringstream lineStream(line);
        std::string lineName;

        if (std::getline(lineStream, lineName, ':')) {
            std::string currentStationName;

            if (lineStream >> std::quoted(currentStationName)) {
                int currentStationID = getOrCreateID(currentStationName);

                int weight;
                std::string nextStationName;

                while (lineStream >> weight >> std::quoted(nextStationName)) {
                    int nextStationID = getOrCreateID(nextStationName);

                    stations[currentStationID].addEdge(nextStationID, weight, lineName);
                    stations[nextStationID].addEdge(currentStationID, weight, lineName);

                    currentStationID = nextStationID;
                }
            }
        }
    }

    fileStream.close();
    return true;
}

void Graph::printGraph() const {
    std::cout << "\n--- GRAPH DEBUG AUSGABE ---\n";
    for (const auto& station : stations) {
        std::cout << "Station ID " << station.getID() << ": \"" << station.getName() << "\"\n";
        for (const auto& edge : station.getAdjacencies()) {
            std::cout << "  -> faehrt mit " << edge.getLine()
                      << " in " << edge.getWeight() << " Min zu Station ID "
                      << edge.getDestinationID() << " (\""
                      << stations[edge.getDestinationID()].getName() << "\")\n";
        }
    }
    std::cout << "---------------------------\n";
}

void Graph::findShortestPath(const std::string& startName, const std::string& destName) {
    // algorithm isnt implemented yet
    std::cout << "Wegsuche von " << startName << " nach " << destName << " noch nicht implementiert.\n";
}