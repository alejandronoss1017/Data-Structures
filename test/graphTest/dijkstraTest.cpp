#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../../include/graph/Graph.hpp"

#include <map>
#include <vector>
#include <string>

using namespace std;

TEST_CASE("Test dijkstra", "[dijkstra]")
{
    Graph<string, string> graph;

    vector<string> path;

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

    map<Node<string, string>, double> result = graph.dijkstra("A");

    REQUIRE(result.size() == 7);
    REQUIRE(result.at(Node<string, string>("A", 0,"C++")) == 0);
    REQUIRE(result.at(Node<string, string>("B", 1,"Java")) == 5);
    REQUIRE(result.at(Node<string, string>("C", 2,"Python")) == 2);
    REQUIRE(result.at(Node<string, string>("D", 3,"JavaScript")) == 7);
    REQUIRE(result.at(Node<string, string>("E", 4,"Go")) == 1);
    REQUIRE(result.at(Node<string, string>("F", 5,"C#")) == 11);
    REQUIRE(result.at(Node<string, string>("G", 6,"PHP")) == 3);
}

TEST_CASE("Test dijkstra2", "[dijkstra]")
{
    Graph<string, int> graph;
    graph.addNode("A", 100);
    graph.addNode("B", 200);
    graph.addNode("C", 300);
    graph.addNode("D", 400);

    graph.addEdge("A", "B", 10);
    graph.addEdge("A", "C", 3);
    graph.addEdge("B", "C", 1);
    graph.addEdge("B", "D", 2);
    graph.addEdge("C", "B", 4);
    graph.addEdge("C", "D", 8);

    map<Node<string, int>, double> distances = graph.dijkstra("A");

    REQUIRE(distances.size() == 4);
    REQUIRE(distances[Node<string, int>("A", 0, 100)] == 0);
    REQUIRE(distances[Node<string, int>("B", 1, 200)] == 7);
    REQUIRE(distances[Node<string, int>("C", 2, 300)] == 3);
    REQUIRE(distances[Node<string, int>("D", 3, 400)] == 9);
}
