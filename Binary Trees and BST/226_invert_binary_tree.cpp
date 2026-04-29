/*
 * 226. Invert Binary Tree
 * https://leetcode.com/problems/invert-binary-tree/
 * Difficulty: Easy
 *
 *
 * ─────────────────────────────────────────────────────────
 * APPROACH 1 — Recursive Post-order   Time: O(n)  Space: O(h)
 * APPROACH 2 — Recursive Pre-order    Time: O(n)  Space: O(h)
 * APPROACH 3 — Iterative BFS          Time: O(n)  Space: O(n)
 * APPROACH 4 — Iterative DFS (stack)  Time: O(n)  Space: O(h)
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
// APPROACH 1: Recursive Post-order
// Invert children first, then swap — matches your diam2() style
// ─────────────────────────────────────────────────────────
class Solution1 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;

        TreeNode* left  = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        root->left  = right;
        root->right = left;

        return root;
    }
};

// ─────────────────────────────────────────────────────────
// APPROACH 2: Recursive Pre-order
// Swap first, then recurse — same result, different order
// ─────────────────────────────────────────────────────────
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;

        swap(root->left, root->right);  // swap at current node first

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

// ─────────────────────────────────────────────────────────
// APPROACH 3: Iterative BFS
// Process level by level; swap children of each node
// Mirrors the spirit of your levelOrder() with queue
// ─────────────────────────────────────────────────────────
class Solution3 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;

        queue<TreeNode*> Q;
        Q.push(root);

        while (!Q.empty()) {
            TreeNode* curr = Q.front(); Q.pop();
            swap(curr->left, curr->right);
            if (curr->left)  Q.push(curr->left);
            if (curr->right) Q.push(curr->right);
        }
        return root;
    }
};

// ─────────────────────────────────────────────────────────
// APPROACH 4: Iterative DFS with stack
// Same idea as BFS but uses stack — pre-order traversal
// ─────────────────────────────────────────────────────────
class Solution4 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* curr = st.top(); st.pop();
            swap(curr->left, curr->right);
            if (curr->left)  st.push(curr->left);
            if (curr->right) st.push(curr->right);
        }
        return root;
    }
};
