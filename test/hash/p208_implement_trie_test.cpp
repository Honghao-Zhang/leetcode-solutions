#include "hash/hash.h"
#include <gtest/gtest.h>
using namespace std;
using namespace my_hash;

TEST(PrefixTrie, example_1_with_my_implementation)
{
    MyTrie *obj = new MyTrie();
    obj->insert("apple");
    EXPECT_TRUE(obj->search("apple"));
    EXPECT_FALSE(obj->search("app"));
    EXPECT_TRUE(obj->startsWith("app"));
    obj->insert("app");
    EXPECT_TRUE(obj->search("app"));
    delete obj;
}

TEST(PrefixTrie, example_1_with_array)
{
    TrieByArray *obj = new TrieByArray();
    obj->insert("apple");
    EXPECT_TRUE(obj->search("apple"));
    EXPECT_FALSE(obj->search("app"));
    EXPECT_TRUE(obj->startsWith("app"));
    obj->insert("app");
    EXPECT_TRUE(obj->search("app"));
    delete obj;
}

TEST(PrefixTrie, example_1_with_map)
{
    TrieByMap *obj = new TrieByMap();
    obj->insert("apple");
    EXPECT_TRUE(obj->search("apple"));
    EXPECT_FALSE(obj->search("app"));
    EXPECT_TRUE(obj->startsWith("app"));
    obj->insert("app");
    EXPECT_TRUE(obj->search("app"));
    delete obj;
}