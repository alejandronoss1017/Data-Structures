#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../../../include/tree/avlTree/AVLTree.hpp"
#include <vector>
#include <string>

using namespace std;

template <typename T>
bool insert(vector<T> a)
{
    AVLTree<T> tree;

    for (int i = 0; i < a.size(); i++)
    {

        if (!tree.insert(a[i]))
        {
            return false;
        }
    }

    return true;
}

TEST_CASE("Insertion work correctly", "[insert]")
{
    REQUIRE(insert(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) == 1);
    REQUIRE(insert(vector<string>{"HI", "What's up?", "Rock", "Great", "Enjoy"}) == 1);
    REQUIRE(insert(vector<char>{'B', 'S', 'G', 'J', 'T', 'U', 'W', 'P'}) == 1);
}