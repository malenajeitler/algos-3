//
// Created by Malena on 25/05/2026.
//

#ifndef FIND_PATH_EDGE_H
#define FIND_PATH_EDGE_H

#include <string>

class Edge {
public:
    Edge(int destID, int w, std::string line);

    int getDestinationID() const;
    int getWeight() const;
    const std::string& getLine() const;

private:
    int destinationID;
    int weight;
    std::string lineName;
};


#endif //FIND_PATH_EDGE_H