// ============================================================
// Count Unique Substrings (Classic — Suffix Trie)
// No LC number — standard trie/string interview problem
//
// Logic:
//   Key insight: every unique substring is a prefix of some suffix.
//   So insert all suffixes into a trie.
//   Count total nodes in the trie — each node represents exactly
//   one unique prefix of some suffix = one unique substring.
//
// Example: "ab"
//   Suffixes: "ab", "b"
//   Trie nodes: a -> b (2 nodes), b (1 node) = 3 total
//   Unique substrings: "a", "ab", "b" = 3 ✓
// ============================================================

#include <iostream>
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

    // O(L)
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

    // Count all nodes recursively
    int countHelper(Node* node) {
        int ans = 0;
        for (pair<char, Node*> child : node->children) {
            ans += countHelper(child.second);
        }
        return ans + 1; // +1 for this node itself
    }

    int countNodes() {
        return countHelper(root);
    }
};

int countUniqueSubstr(string str) {
    Trie trie;
    for (int i = 0; i < str.size(); i++) {
        string suffix = str.substr(i); // generate each suffix
        trie.insert(suffix);           // insert into trie
    }
    return trie.countNodes(); // each node = one unique substring
}

int main() {
    cout << countUniqueSubstr("ababa") << endl; // 10
    // Suffixes: "ababa","baba","aba","ba","a"
    // Unique substrings: a,ab,aba,abab,ababa,b,ba,bab,baba,babab... count = 10

    cout << countUniqueSubstr("ab") << endl; // 3  (a, ab, b)
    cout << countUniqueSubstr("aa") << endl; // 2  (a, aa)
    return 0;
}
