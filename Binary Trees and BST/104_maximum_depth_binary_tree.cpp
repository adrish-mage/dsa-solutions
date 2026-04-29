/*
 * 104. Maximum Depth of Binary Tree
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * Difficulty: Easy
 *
 *
 * ─────────────────────────────────────────────────────────
 * APPROACH 1 — Recursive DFS (your height() style)
 *                              Time: O(n)  Space: O(h)
 * APPROACH 2 — Iterative BFS (level-count)
 *                              Time: O(n)  Space: O(n)
 * APPROACH 3 — Iterative DFS with stack
 *                              Time: O(n)  Space: O(h)
 * ─────────────────────────────────────────────────────────
 */

#include <queue>
#include <stack>
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
// APPROACH 1: Recursive — direct translation of your height()
// max(leftHeight, rightHeight) + 1 at every node
// ─────────────────────────────────────────────────────────
class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int left  = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};

// ─────────────────────────────────────────────────────────
// APPROACH 2: Iterative BFS — count levels
// Each time we finish a level, increment depth
// ─────────────────────────────────────────────────────────
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;

        queue<TreeNode*> Q;
        Q.push(root);
        int depth = 0;

        while (!Q.empty()) {
            int sz = Q.size();
            depth++;
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = Q.front(); Q.pop();
                if (curr->left)  Q.push(curr->left);
                if (curr->right) Q.push(curr->right);
            }
        }
        return depth;
    }
};

// ─────────────────────────────────────────────────────────
// APPROACH 3: Iterative DFS with explicit stack
// Store {node, depth} pairs; track running max depth
// ─────────────────────────────────────────────────────────
class Solution3 {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        int maxD = 0;

        while (!st.empty()) {
            auto [node, depth] = st.top(); st.pop();
            maxD = max(maxD, depth);
            if (node->left)  st.push({node->left,  depth + 1});
            if (node->right) st.push({node->right, depth + 1});
        }
        return maxD;
    }
};
