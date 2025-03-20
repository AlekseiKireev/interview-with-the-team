#include <gtest/gtest.h>
#include "graph.h"
#include <chrono>

// Исходный тест
TEST(UndirectedShortestPathFinderTest, CustomInput) {
    UndirectedGraph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);

    UndirectedShortestPathFinder finder(graph, 4);
    const auto& distances = finder.getDistances();

    EXPECT_EQ(distances[0], 1);
    EXPECT_EQ(distances[1], 2);
    EXPECT_EQ(distances[2], 3);
    EXPECT_EQ(distances[3], 3);
    EXPECT_EQ(distances[4], 0);
}

// Тест базовой функциональности графа
TEST(UndirectedGraphTest, BasicFunctionality) {
    UndirectedGraph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    EXPECT_EQ(graph.getNumVertices(), 5);
    EXPECT_EQ(graph.getNeighbors(1).size(), 2);

}

// Тест поиска кратчайшего пути
TEST(UndirectedShortestPathFinderTest, ShortestPath) {
    UndirectedGraph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    UndirectedShortestPathFinder finder(graph, 0);
    const auto& distances = finder.getDistances();

    EXPECT_EQ(distances[0], 0);
    EXPECT_EQ(distances[1], 1);
    EXPECT_EQ(distances[2], 2);
    EXPECT_EQ(distances[3], 3);
    EXPECT_EQ(distances[4], 4);
}

// Нагрузочный тест: проверяет работу BFS на большом графе
TEST(PerformanceTest, LargeGraphBFS) {
    const int numVertices = 10000;
    UndirectedGraph graph(numVertices);

    // Создаем цепочку (линейный граф): 0 - 1 - 2 - ... - 9999
    for (int i = 0; i < numVertices - 1; ++i) {
        graph.addEdge(i, i + 1);
    }

    auto startTime = std::chrono::high_resolution_clock::now();
    UndirectedShortestPathFinder finder(graph, 0);
    auto endTime = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = endTime - startTime;
    std::cout << "BFS completed in " << duration.count() << " seconds.\n";

    const auto& distances = finder.getDistances();
    for (int i = 0; i < numVertices; ++i) {
        EXPECT_EQ(distances[i], i);
    }


    EXPECT_LT(duration.count(), 1.0);
}


// повторяющиеся ребра
TEST(UndirectedGraphTest, DuplicateEdges) {
    UndirectedGraph graph(2);

    for (int i = 0; i < 10; ++i) {
        graph.addEdge(0, 1);
    }


    const auto& neighbors0 = graph.getNeighbors(0);
    const auto& neighbors1 = graph.getNeighbors(1); 

    EXPECT_EQ(neighbors0.size(), 1);  
    EXPECT_EQ(neighbors1.size(), 1);  

    EXPECT_TRUE(neighbors0.count(1) > 0);
    EXPECT_TRUE(neighbors1.count(0) > 0);
}

 
// цикл
TEST(UndirectedShortestPathFinderTest, ComplexCycle) {
    UndirectedGraph graph(7);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    UndirectedShortestPathFinder finder(graph, 0);
    const auto& distances = finder.getDistances();

    EXPECT_EQ(distances[0], 0);
    EXPECT_EQ(distances[1], 1);
    EXPECT_EQ(distances[2], 2);
    EXPECT_EQ(distances[3], 1);
    EXPECT_EQ(distances[4], 2);
    EXPECT_EQ(distances[5], 3);
    EXPECT_EQ(distances[6], 4);
}


// Запуск Google Test
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
