#ifndef MY_SOLUTIONS_HASH_H
#define MY_SOLUTIONS_HASH_H
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <unordered_map>

namespace my_hash
{
    // 763 partition labels
    std::vector<int> partitionLabels(std::string s);
    // 208 implement MyTrie
    struct MyTrieNode
    {
        char c;
        std::vector<std::shared_ptr<MyTrieNode>> next;
        MyTrieNode() : c{'\0'}, next{std::vector<std::shared_ptr<MyTrieNode>>(27, nullptr)} {}
        MyTrieNode(char character) : c{character}, next{std::vector<std::shared_ptr<MyTrieNode>>(27, nullptr)} {}
    };

    class MyTrie
    {
    public:
        MyTrie();
        ~MyTrie();
        void insert(std::string word);
        bool search(std::string word);
        bool startsWith(std::string prefix);

    private:
        std::shared_ptr<MyTrieNode> m_head;
    };

    class TrieByArray
    {
    public:
        TrieByArray();
        ~TrieByArray(); // the implementation of destructor is also interesting
        void insert(std::string word);
        bool search(std::string word);
        bool startsWith(std::string prefix);

    private:
        TrieByArray *m_next[26] = {}; // convenient way to initalize array
        bool m_is_word{false};
    };

    class TrieByMap
    {
    public:
        TrieByMap();
        ~TrieByMap();
        void insert(std::string word);
        bool search(std::string word);
        bool startsWith(std::string prefix);

    private:
        std::unordered_map<char, TrieByMap *> m_next;
        bool m_is_word = false;
    };
}

#endif