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

TEST_CASE("Insertion work correctly", "[insert]")
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