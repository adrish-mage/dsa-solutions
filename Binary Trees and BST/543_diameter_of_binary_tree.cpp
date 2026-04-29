/*
 * 543. Diameter of Binary Tree
 * https://leetcode.com/problems/diameter-of-binary-tree/
 * Difficulty: Easy
 *
 * From your code:
 *   diam1(Node* root) — O(n²) brute force  — code.cpp line 134
 *   diam2(Node* root) — O(n)  optimal       — code.cpp line 146
 *
 * NOTE: Your diam counts nodes on path (leftH + rightH + 1).
 * LC counts EDGES (leftH + rightH). Adjusted below.
 *
 * ─────────────────────────────────────────────────────────
 * APPROACH 1 — Brute Force O(n²): your diam1() style
 *                              Time: O(n²)  Space: O(h)
 * APPROACH 2 — Optimal O(n):   your diam2() style (pair)
 *                              Time: O(n)   Space: O(h)
 * APPROACH 3 — Optimal O(n):   global variable style (cleaner)
 *                              Time: O(n)   Space: O(h)
 * ─────────────────────────────────────────────────────────
 */

#include <algorithm>
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
// APPROACH 1: Brute Force — your diam1() style
// At each node: height(left) + height(right) = edge-diameter through it
// Call height() separately → O(n) per node → O(n²) total
// ─────────────────────────────────────────────────────────
class Solution1 {
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        // diameter through this node (in edges = heights, not +1 like your nodes version)
        int currDiam  = height(root->left) + height(root->right);
        int leftDiam  = diameterOfBinaryTree(root->left);
        int rightDiam = diameterOfBinaryTree(root->right);

        return max(currDiam, max(leftDiam, rightDiam));
    }
};

// ─────────────────────────────────────────────────────────
// APPROACH 2: Optimal — your diam2() pair style
// Return {diameter, height} from each subtree in one pass
// ─────────────────────────────────────────────────────────
class Solution2 {
    // returns {diameter (edges), height}
    pair<int,int> solve(TreeNode* root) {
        if (root == NULL) return {0, 0};

        auto [leftDiam,  leftH]  = solve(root->left);
        auto [rightDiam, rightH] = solve(root->right);

        int currDiam  = leftH + rightH;           // edges through this node
        int finalDiam = max(currDiam, max(leftDiam, rightDiam));
        int finalH    = max(leftH, rightH) + 1;

        return {finalDiam, finalH};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first;
    }
};

// ─────────────────────────────────────────────────────────
// APPROACH 3: Optimal — global variable style (most common in interviews)
// Track maxDiam as a class member; return only height from helper
// ─────────────────────────────────────────────────────────
class Solution3 {
    int maxDiam = 0;

    int height(TreeNode* root) {
        if (root == NULL) return 0;
        int leftH  = height(root->left);
        int rightH = height(root->right);
        maxDiam = max(maxDiam, leftH + rightH);  // update diameter (edges)
        return max(leftH, rightH) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDiam;
    }
};
