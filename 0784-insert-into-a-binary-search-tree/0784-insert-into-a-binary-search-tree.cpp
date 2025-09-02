/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insert(TreeNode* root, int val) {
        // If root is NULL, create a new node
        if (root == NULL) 
            return new TreeNode(val);

        if (val < root->val) {
            // Insert in left subtree
            root->left = insert(root->left, val);
        } else {
            // Insert in right subtree
            root->right = insert(root->right, val);
        }
        return root; // return updated root
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insert(root, val);
    }
};
