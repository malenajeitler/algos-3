#include "Graph.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::cout << "PROGRAMM GESTARTET!" << std::endl;

    if (argc != 4) {
        std::cerr << "Fehler: Falsche Anzahl an Argumenten!" << std::endl;
        std::cerr << "Verwendung: " << argv[0] << " filename_graph start ziel" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string startStation = argv[2];
    std::string targetStation = argv[3];

    Graph network;

    std::cout << "Lade Graphen aus Datei: '" << filename << "'...\n";


    if (!network.loadFromFile(filename)) {
        std::cerr << "Fehler: Das Verkehrsnetz konnte nicht geladen werden.\n";
        return 1;
    }

    std::cout << "Netzwerk erfolgreich geladen. Starte Wegsuche...\n";
    std::cout << "Start: " << startStation << "\n";
    std::cout << "Ziel:  " << targetStation << "\n\n";

    network.printGraph();
    network.findShortestPath(startStation, targetStation);
    // algorithm isnt implemented yet

    return 0;
}


/*


#include <iostream>
#include "Edge.h"
#include "Station.h"
#include <vector>

int main() {
    Edge test(2, 4, "U4");

    std::cout << "dest id: " << test.getDestinationID() << std::endl;
    std::cout << "weight: " << test.getWeight() << std::endl;
    std::cout << "line name: " << test.getLine() << std::endl;

    Station station(2, "Karlsplatz");
    station.addEdge(2, 4, "U4");
    station.addEdge(3, 4, "U4");
    station.addEdge(4, 5, "U4");

    std::vector<Edge> vector= station.getAdjacencies();

    std::cout << "station id: " << station.getID() << std::endl;
    std::cout << "name: " << station.getName() << std::endl;


    for (auto & element : vector) {
        std::cout << "dest id: " << element.getDestinationID() << std::endl;
        std::cout << "weight: " << element.getWeight() << std::endl;
        std::cout << "line name: " << element.getLine() << std::endl;
    }



    return 0;
}

*/