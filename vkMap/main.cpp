#include <iostream>
#include <fstream>
#include "graph.h"

int main() {
    ifstream inputFile("graph.txt");

    int numVertices, numEdges;
    inputFile >> numVertices >> numEdges;

    auto graph = make_unique<UndirectedGraph>(numVertices);

    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        inputFile >> u >> v;
        graph->addEdge(u, v);
    }

    int startVertex;
    inputFile >> startVertex;

    UndirectedShortestPathFinder finder(*graph, startVertex);

    for (int i = 0; i < graph->getNumVertices(); ++i) {
        cout << finder.getDistances()[i] << endl;
    }

    return 0;
}