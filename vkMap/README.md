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
    * при написании кода использовался стандарт 23 года

* Знание  алгоритмов STL и стандартных контейнеров.
    * см. файл graph.cpp

* Понимание парадигмы ООП.
    * см. файл graph.h

* Базовое знание Git.
    * использовался при работе с github

* Опыт работы с командной строкой Linux.
    * элементы работы можно заметить в interview-with-the-team/.github/workflows/VkMapTest.yml

* Умение работать с CMake.
    * есть соответстсвующий файл, необходим для interview-with-the-team/.github/workflows/VkMapTest.yml

* Умение работать с CI/CD.
    * Обратите внимание, что код протестирован в github actions

