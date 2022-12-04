#include "hash/hash.h"
using namespace std;
using namespace my_hash;

// my first solution
MyTrie::MyTrie()
{
    m_head = make_shared<MyTrieNode>();
}

MyTrie::~MyTrie()
{
}

void MyTrie::insert(string word)
{
    if (word.empty())
        return;
    shared_ptr<MyTrieNode> cur = m_head;
    for (auto idx = 0; idx < word.size(); ++idx)
    {
        if (cur->next[word[idx] - 'a'] != nullptr)
        {
            if (cur->next[word[idx] - 'a']->c != word[idx])
            {
                std::cout << "ERROR: char is not at right place" << std::endl;
            }
        }
        else
        {
            // don't do cur = make_shared<MyTrieNode>() here, because this only
            // changes the value of cur, not the value of cur->next[word[idx] - 'a']
            cur->next[word[idx] - 'a'] = make_shared<MyTrieNode>(word[idx]);
        }
        cur = cur->next[word[idx] - 'a'];
    }
    cur->next[26] = make_shared<MyTrieNode>();
}

bool MyTrie::search(string word)
{
    if (word.empty())
        return false;
    shared_ptr<MyTrieNode> cur = m_head;
    for (auto idx = 0; idx < word.size(); ++idx)
    {
        cur = cur->next[word[idx] - 'a'];
        if (cur == nullptr)
            return false;
        if (cur->c != word[idx])
        {
            std::cout << "ERROR: this should not happen" << std::endl;
            return false;
        }
    }
    if (cur->next[26] != nullptr && cur->next[26]->c == '\0')
        return true;
    else
    {
        std::cout << "ERROR: this is only a prefix of other word" << std::endl;
        return false;
    }
}

bool MyTrie::startsWith(string prefix)
{
    if (prefix.empty())
        return false;
    shared_ptr<MyTrieNode> cur = m_head;
    for (auto idx = 0; idx < prefix.size(); ++idx)
    {
        cur = cur->next[prefix[idx] - 'a'];
        if (cur == nullptr)
            return false;
        if (cur->c != prefix[idx])
        {
            std::cout << "ERROR: this should not happen" << std::endl;
            return false;
        }
    }
    return true;
}

//====================================================================================================
// solution 1: implement by using array
TrieByArray::TrieByArray() {}

TrieByArray::~TrieByArray()
{
    for (auto idx = 0; idx < 26; idx++)
    {
        // bool flag = false;
        // if (m_next[idx])
        //     flag = true;
        // if (flag)
        //     std::cout << "before delete: " << idx << std::endl;
        delete m_next[idx];
        // if (flag)
        //     std::cout << "after delete: " << idx << std::endl;
    }
}

void TrieByArray::insert(string s)
{
    if (s.empty())
        return;
    TrieByArray *cur = this;
    for (auto c : s)
    {
        int idx = c - 'a';
        if (!cur->m_next[idx])
            cur->m_next[idx] = new TrieByArray();
        cur = cur->m_next[idx];
    }
    cur->m_is_word = true;
}

bool TrieByArray::search(string s)
{
    if (s.empty())
        return false;
    TrieByArray *cur = this;
    for (auto c : s)
    {
        int idx = c - 'a';
        if (!cur->m_next[idx])
            return false;
        cur = cur->m_next[idx];
    }
    return cur->m_is_word;
}

bool TrieByArray::startsWith(string s)
{
    if (s.empty())
        return false;
    TrieByArray *cur = this;
    for (auto c : s)
    {
        int idx = c - 'a';
        if (!cur->m_next[idx])
            return false;
        cur = cur->m_next[idx];
    }
    return true;
}

//====================================================================================================
// solution 2: implement by using unordered_map
TrieByMap::TrieByMap() {}

TrieByMap::~TrieByMap()
{
    for (auto p : m_next)
    {
        delete p.second;
    }
}

void TrieByMap::insert(string s)
{
    if (s.empty())
        return;
    TrieByMap *cur = this;
    for (auto c : s)
    {
        if (cur->m_next.find(c) == m_next.end())
            cur->m_next[c] = new TrieByMap();
        cur = cur->m_next[c];
    }
    cur->m_is_word = true;
}

bool TrieByMap::search(string s)
{
    if (s.empty())
        return false;
    TrieByMap *cur = this;
    for (auto c : s)
    {
        if (cur->m_next.find(c) == m_next.end())
            return false;
        cur = cur->m_next[c];
    }
    return cur->m_is_word;
}

bool TrieByMap::startsWith(string s)
{
    if (s.empty())
        return false;
    TrieByMap *cur = this;
    for (auto c : s)
    {
        if (cur->m_next.find(c) == m_next.end())
            return false;
        cur = cur->m_next[c];
    }
    return true;
}