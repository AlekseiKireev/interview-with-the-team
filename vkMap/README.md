Искомая реализация: 

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

все остальное -- демонстрация е требованиям: 

* Базовые знания C++ не ниже 14 стандарта.
    * с

Знание  алгоритмов STL и стандартных контейнеров.

Понимание парадигмы ООП.

Базовое знание Git.

Опыт работы с командной строкой Linux.

Умение работать с CMake.

Умение работать с CI/CD.
