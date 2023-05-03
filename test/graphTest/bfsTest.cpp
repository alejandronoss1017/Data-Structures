#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../../include/graph/Graph.hpp"

#include <vector>
#include <string>

using namespace std;

TEST_CASE("Test breadthFirstSearch", "[breadthFirstSearch]")
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

    auto result = graph.breadthFirstSearch("A");

    // Verify that the search returns the correct nodes in the correct order
    REQUIRE(result.size() == 7);
    REQUIRE(result[0].getId() == "A");
    REQUIRE(result[1].getId() == "B");
    REQUIRE(result[2].getId() == "C");
    REQUIRE(result[3].getId() == "E");
    REQUIRE(result[4].getId() == "D");
    REQUIRE(result[5].getId() == "F");
    REQUIRE(result[6].getId() == "G");
}