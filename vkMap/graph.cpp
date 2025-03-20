#include "graph.h"

UndirectedGraph::UndirectedGraph(int numVertices) : adjacencyList(numVertices) {}

void UndirectedGraph::addEdge(int u, int v) {
    adjacencyList[u].insert(v);
    adjacencyList[v].insert(u);
}

const unordered_set<int>& UndirectedGraph::getNeighbors(int vertex) const {
    return adjacencyList[vertex];
}

int UndirectedGraph::getNumVertices() const {
    return adjacencyList.size();
}

UndirectedShortestPathFinder::UndirectedShortestPathFinder(const UndirectedGraph& graph, int start)
    : distances(graph.getNumVertices(), numeric_limits<int>::max()) {
    bfs(graph, start);
}

void UndirectedShortestPathFinder::bfs(const UndirectedGraph& graph, int start) {
    queue<int> q;
    q.push(start);
    distances[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph.getNeighbors(current)) {
            if (distances[neighbor] == numeric_limits<int>::max()) {
                distances[neighbor] = distances[current] + 1;
                q.push(neighbor);
            }
        }
    }
} 

const vector<int>& UndirectedShortestPathFinder::getDistances() const {
    return distances;
}
