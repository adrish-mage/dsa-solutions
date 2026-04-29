/*
 * 102. Binary Tree Level Order Traversal
 * https://leetcode.com/problems/binary-tree-level-order-traversal/
 * Difficulty: Medium
 *
 * ─────────────────────────────────────────────────────────
 * APPROACH 1 — BFS with NULL sentinel (your style)
 *                              Time: O(n)  Space: O(n)
 * APPROACH 2 — BFS with level size counter
 *                              Time: O(n)  Space: O(n)
 * APPROACH 3 — Recursive DFS with depth tracking
 *                              Time: O(n)  Space: O(h)
 * ─────────────────────────────────────────────────────────
 */

#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// ─────────────────────────────────────────────────────────
// APPROACH 1: BFS with NULL sentinel (your original style)
// Push NULL after each level to detect level boundaries
// ─────────────────────────────────────────────────────────
class Solution1 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;

        queue<TreeNode*> Q;
        Q.push(root);
        Q.push(NULL);           

        vector<int> currLevel;

        while (!Q.empty()) {
            TreeNode* curr = Q.front();
            Q.pop();

            if (curr == NULL) {
                result.push_back(currLevel);
                currLevel.clear();
                if (!Q.empty())
                    Q.push(NULL);   
            } else {
                currLevel.push_back(curr->val);
                if (curr->left)  Q.push(curr->left);
                if (curr->right) Q.push(curr->right);
            }
        }
        return result;
    }
};

// ─────────────────────────────────────────────────────────
// APPROACH 2: BFS with level-size counter (cleaner / common)
// Snapshot queue size at start of each level → that many nodes belong to it
// ─────────────────────────────────────────────────────────
class Solution2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;

        queue<TreeNode*> Q;
        Q.push(root);

        while (!Q.empty()) {
            int sz = Q.size();      // nodes in this level
            vector<int> currLevel;

            for (int i = 0; i < sz; i++) {
                TreeNode* curr = Q.front(); Q.pop();
                currLevel.push_back(curr->val);
                if (curr->left)  Q.push(curr->left);
                if (curr->right) Q.push(curr->right);
            }
            result.push_back(currLevel);
        }
        return result;
    }
};

// ─────────────────────────────────────────────────────────
// APPROACH 3: Recursive DFS with depth index
// Pass depth down; result[depth] is the level's vector
// Space: O(h) stack — better for tall trees
// ─────────────────────────────────────────────────────────
class Solution3 {
    void dfs(TreeNode* root, int depth, vector<vector<int>>& result) {
        if (root == NULL) return;
        if (depth == (int)result.size())
            result.push_back({});       // start a new level
        result[depth].push_back(root->val);
        dfs(root->left,  depth + 1, result);
        dfs(root->right, depth + 1, result);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);
        return result;
    }
};
