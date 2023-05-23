#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../../include/graph/Graph.hpp"

#include <limits>
#include <vector>

using namespace std;

TEST_CASE("Floyd-Warshall algorithm test", "[floydWarshall]")
{
    Graph<int, int> graph;

    // Add nodes
    graph.addNode(1, 1);
    graph.addNode(2, 2);
    graph.addNode(3, 3);

    // Add edges
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 4);
    graph.addEdge(2, 3, 1);

    // Run the Floyd-Warshall algorithm
    auto distances = graph.floydWarshall();

    // Check the distances
    REQUIRE(distances[0][0] == 0);
    REQUIRE(distances[0][1] == 2);
    REQUIRE(distances[0][2] == 3);
    REQUIRE(distances[1][0] == std::numeric_limits<double>::infinity());
    REQUIRE(distances[1][1] == 0);
    REQUIRE(distances[1][2] == 1);
    REQUIRE(distances[2][0] == std::numeric_limits<double>::infinity());
    REQUIRE(distances[2][1] == std::numeric_limits<double>::infinity());
    REQUIRE(distances[2][2] == 0);
}