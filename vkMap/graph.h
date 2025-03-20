#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <memory>
#include <unordered_set>

using namespace std;

class Graph {
public:
    virtual void addEdge(int u, int v) = 0;
    virtual const unordered_set<int>& getNeighbors(int vertex) const = 0;
    virtual int getNumVertices() const = 0;
    virtual ~Graph() = default;
};

class UndirectedGraph : public Graph {
private:
    vector<unordered_set<int>> adjacencyList;

public:
    explicit UndirectedGraph(int numVertices);
    void addEdge(int u, int v) override;
    const unordered_set<int>& getNeighbors(int vertex) const override;
    int getNumVertices() const override;
};

class UndirectedShortestPathFinder {
private:
    vector<int> distances;

public:
    explicit UndirectedShortestPathFinder(const UndirectedGraph& graph, int start);
    void bfs(const UndirectedGraph& graph, int start);
    const vector<int>& getDistances() const;
};

#endif 