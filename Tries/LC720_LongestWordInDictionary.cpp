// ============================================================
// LC 720 - Longest Word in Dictionary
// https://leetcode.com/problems/longest-word-in-dictionary/
//
// Logic:
//   Insert all words. DFS the trie — only continue down a branch
//   if the current node has endOfWord = true (meaning every prefix
//   of this path is itself a valid word in the dict).
//   Track longest string; on tie pick lexicographically smaller.
// ============================================================

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string key) {
        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    void longestHelper(Node* node, string& ans, string temp) {
        for (pair<char, Node*> child : node->children) {
            if (child.second->endOfWord) {
                temp += child.first;

                // update answer: prefer longer, on tie prefer lexicographically smaller
                if ((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size())) {
                    ans = temp;
                }
                longestHelper(child.second, ans, temp);
                temp = temp.substr(0, temp.size() - 1); // backtrack
            }
        }
    }

    string longestStringWithEOW() {
        string ans = "";
        longestHelper(root, ans, "");
        return ans;
    }
};

string longestWord(vector<string>& words) {
    Trie trie;
    for (int i = 0; i < words.size(); i++) {
        trie.insert(words[i]);
    }
    return trie.longestStringWithEOW();
}

int main() {
    vector<string> words = {"w", "wo", "wor", "worl", "world"};
    cout << longestWord(words) << endl; // "world"

    vector<string> words2 = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << longestWord(words2) << endl; // "apple"
    return 0;
}
