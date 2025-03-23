#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

class TrieNode
{
public:
    TrieNode *character[26];
    bool isEnd;

    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            character[i] = nullptr;
        isEnd = false;
    }
};

// Design a data structure that supports adding new words and finding if a string matches any previously added string.
// Implement the WordDictionary class:
// WordDictionary() Initializes the object.
// void addWord(word) Adds word to the data structure, it can be matched later.
// bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. 
// word may contain dots '.' where dots can be matched with any letter.
class WordDictionary
{
public:
    TrieNode *root;
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (!node->character[index])
                node->character[index] = new TrieNode();
            node = node->character[index];
        }
        node->isEnd = true;
    }
    bool dfs(string &word, int index, TrieNode *node)
    {
        if (!node)
            return false;
        if (index == word.size())
            return node->isEnd;

        char c = word[index];
        if (c == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                if (node->character[i] && dfs(word, index + 1, node->character[i]))
                    return true;
            }
            return false;
        }
        else
        {
            int idx = c - 'a';
            return dfs(word, index + 1, node->character[idx]);
        }
    }

    bool search(string word)
    {
        return dfs(word, 0, root);
    }
};