// ============================================================
// Shortest Unique Prefix (Classic Interview Problem)
// No LC number — common in Google/Amazon interviews
//
// Logic:
//   Insert all words, tracking freq on each node = how many
//   words pass through it (incremented on every insert traversal).
//   For each word, walk and stop at first node where freq == 1
//   — only one word goes through here, so prefix is already unique.
//
// Bug note in original: freq is reset to 1 even for existing nodes
//   in the else branch — should be freq++ to count correctly.
//   Fixed here.
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
    int freq;
    Node() {
        endOfWord = false;
        freq = 0;
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
            temp->children[key[i]]->freq++;  // count every word passing through
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    // O(L)
    string getPrefix(string key) {
        Node* temp = root;
        string prefix;

        for (int i = 0; i < key.size(); i++) {
            prefix += key[i];
            if (temp->children[key[i]]->freq == 1) {
                break; // only one word goes through here — unique prefix found
            }
            temp = temp->children[key[i]];
        }
        return prefix;
    }
};

void prefixProblem(vector<string> dict) {
    Trie trie;
    for (int i = 0; i < dict.size(); i++) {
        trie.insert(dict[i]);
    }
    for (int i = 0; i < dict.size(); i++) {
        cout << dict[i] << " -> " << trie.getPrefix(dict[i]) << endl;
    }
}

int main() {
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    prefixProblem(words);
    // Expected:
    // the   -> the  (shares t,h with there/their/thee)
    // a     -> a
    // there -> ther
    // their -> thei
    // any   -> an
    // thee  -> thee
    return 0;
}
