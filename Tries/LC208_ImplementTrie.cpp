// ============================================================
// LC 208 - Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/
//
// Logic:
//   insert  : walk char by char, create node if missing, mark endOfWord at last char
//   search  : walk char by char, return false if any char missing, else return endOfWord
//   startsWith: same as search but always return true if path exists (no endOfWord check)
// ============================================================

#include <iostream>
#include <unordered_map>
#include <string>
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

    // O(L) where L = length of key
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

    // O(L)
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

    // O(L)
    bool startsWith(string prefix) {
        Node* temp = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (temp->children.count(prefix[i])) {
                temp = temp->children[prefix[i]];
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;   // 1
    cout << trie.search("app") << endl;     // 0
    cout << trie.startsWith("app") << endl; // 1
    trie.insert("app");
    cout << trie.search("app") << endl;     // 1
    return 0;
}
