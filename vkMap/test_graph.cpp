#include <gtest/gtest.h>
#include "graph.h"

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

TEST(UndirectedGraphTest, BasicFunctionality) {
    UndirectedGraph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    EXPECT_EQ(graph.getNumVertices(), 5);
    EXPECT_EQ(graph.getNeighbors(1).size(), 2);
    EXPECT_EQ(graph.getNeighbors(1)[0], 0);
    EXPECT_EQ(graph.getNeighbors(1)[1], 2);
}

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


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
