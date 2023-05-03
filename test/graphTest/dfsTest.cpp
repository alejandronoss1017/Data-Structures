#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../../include/graph/Graph.hpp"

#include <vector>
#include <string>

using namespace std;

TEST_CASE("Test depthFirstSearch", "[depthFirstSearch]")
{
    Graph<string, string> graph;

    graph.addNode("A", "C++");
    graph.addNode("B", "Java");
    graph.addNode("C", "Python");
    graph.addNode("D", "JavaScript");
    graph.addNode("E", "Go");
    graph.addNode("F", "C#");
    graph.addNode("G", "PHP");

    graph.addEdge("A", "B", 5);
    graph.addEdge("A", "C", 2);
    graph.addEdge("A", "E", 1);

    graph.addEdge("B", "D", 2);
    graph.addEdge("B", "F", 6);

    graph.addEdge("C", "G", 1);

    graph.addEdge("F", "G", 1);

    auto result = graph.depthFirstSearch("A");

    REQUIRE(result.size() == 7);
    REQUIRE(result[0].getId() == "A");
    REQUIRE(result[1].getId() == "B");
    REQUIRE(result[2].getId() == "D");
    REQUIRE(result[3].getId() == "F");
    REQUIRE(result[4].getId() == "G");
    REQUIRE(result[5].getId() == "C");
    REQUIRE(result[6].getId() == "E");
}