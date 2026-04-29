/*
 * 94. Binary Tree Inorder Traversal
 * https://leetcode.com/problems/binary-tree-inorder-traversal/
 * Difficulty: Easy
 *
 * From your code: inOrder(Node* root) — code.cpp line 60
 * Adapted to collect into vector instead of printing.
 *
 * ─────────────────────────────────────────────────────────
 * APPROACH 1 — Recursive          Time: O(n)  Space: O(h)
 * APPROACH 2 — Iterative (stack)  Time: O(n)  Space: O(h)
 * APPROACH 3 — Morris Traversal   Time: O(n)  Space: O(1)
 * ─────────────────────────────────────────────────────────
 */

#include <vector>
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
// APPROACH 1: Recursive
// Directly mirrors your inOrder() — collect instead of cout
// ─────────────────────────────────────────────────────────
class Solution1 {
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;
        inorder(root->left, ans);   // left
        ans.push_back(root->val);   // root
        inorder(root->right, ans);  // right
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

// ─────────────────────────────────────────────────────────
// APPROACH 2: Iterative with explicit stack
// Manually simulates the recursive call stack
// ─────────────────────────────────────────────────────────
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != NULL || !st.empty()) {
            while (curr != NULL) {   // drill left
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top(); st.pop();
            ans.push_back(curr->val);
            curr = curr->right;      // move to right subtree
        }
        return ans;
    }
};

// ─────────────────────────────────────────────────────────
// APPROACH 3: Morris Traversal — true O(1) space
// Threads NULL right pointers to predecessor temporarily,
// then restores them. No stack or recursion needed.
// ─────────────────────────────────────────────────────────
class Solution3 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                // find inorder predecessor (rightmost of left subtree)
                TreeNode* pre = curr->left;
                while (pre->right != NULL && pre->right != curr)
                    pre = pre->right;

                if (pre->right == NULL) {
                    pre->right = curr;   // make thread
                    curr = curr->left;
                } else {
                    pre->right = NULL;              // remove thread
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
