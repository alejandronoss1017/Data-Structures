#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../../include/graph/Graph.hpp"

#include <vector>
#include <string>

using namespace std;

template <typename K, typename T>
bool insert(vector<pair<K, T>> a)
{
    Graph<K, T> graph;

    for (auto &&tuple : a)
    {
        if (!graph.addNode(tuple.first, tuple.second))
        {
            return false;
        }
    }

    return true;
}

TEST_CASE("Insertion test", "[insert]")
{
    vector<pair<int, int>> numbers = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    vector<pair<int, int>> numbersFail = {{1, 2}, {2, 3}, {3, 4}, {3, 5}};

    vector<pair<string, string>> words = {{"HI", "What's up?"}, {"Rock", "Great"}, {"Enjoy", "Life"}};
    vector<pair<string, string>> wordsFail = {{"HI", "What's up?"}, {"Rock", "Great"}, {"Rock", "Life"}};

    vector<pair<char, string>> letters =
        {{'A', "C++"},
         {'B', "Java"},
         {'C', "Rust"},
         {'D', "Python"},
         {'E', "C#"},
         {'F', "Scala"},
         {'G', "Kotlin"},
         {'H', "Ruby"},
         {'I', "PHP"},
         {'J', "JS"},
         {'K', "Go"}};
    vector<pair<char, string>> lettersFail =
        {{'A', "C++"},
         {'B', "Java"},
         {'C', "Rust"},
         {'D', "Python"},
         {'E', "C#"},
         {'F', "Scala"},
         {'G', "Kotlin"},
         {'C', "Ruby"},
         {'I', "PHP"},
         {'J', "JS"},
         {'K', "Go"}};

    REQUIRE(insert(numbers) == 1);
    REQUIRE(insert(numbersFail) == 0);

    REQUIRE(insert(words) == 1);
    REQUIRE(insert(wordsFail) == 0);

    REQUIRE(insert(letters) == 1);
    REQUIRE(insert(lettersFail) == 0);
}

TEST_CASE("Insertion test2", "[addNode]")
{
    Graph<int, string> graph;

    // Add a node with id 1 and data "Node 1"
    REQUIRE(graph.addNode(1, "Node 1") == true);

    // Check that the node was added correctly
    map<int, Node<int, string>> nodes = graph.getNodes();
    REQUIRE(nodes.size() == 1);
    REQUIRE(nodes[1].getId() == 1);
    REQUIRE(nodes[1].getData() == "Node 1");

    // Try to add a node with the same id, which should fail
    REQUIRE(graph.addNode(1, "Node 2") == false);
}
