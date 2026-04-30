// ============================================================
// LC 139 - Word Break
// https://leetcode.com/problems/word-break/
//
// Logic:
//   Insert all dict words into trie.
//   helper(key): try every split point i from 0 to key.size()-1
//     - if key[0..i] is a valid word in trie
//     - AND helper(key[i+1..]) also returns true
//     - then return true
//   Base case: empty string -> return true (nothing left to break)
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

    bool search(string key) {
        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i])) {
                temp = temp->children[key[i]];
            } else {
                return false;
            }
        }
        return temp->endOfWord;
    }
};

bool helper(Trie& trie, string key) {
    if (key.size() == 0) {
        return true; // nothing left — successful break
    }
    for (int i = 0; i < key.size(); i++) {
        string first  = key.substr(0, i + 1);
        string second = key.substr(i + 1);

        if (trie.search(first) && helper(trie, second)) {
            return true;
        }
    }
    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    Trie trie;
    for (int i = 0; i < wordDict.size(); i++) {
        trie.insert(wordDict[i]);
    }
    return helper(trie, s);
}

int main() {
    vector<string> dict1 = {"leet", "code"};
    cout << wordBreak("leetcode", dict1) << endl; // 1

    vector<string> dict2 = {"apple", "pen"};
    cout << wordBreak("applepenapple", dict2) << endl; // 1

    vector<string> dict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << wordBreak("catsandog", dict3) << endl; // 0
    return 0;
}
