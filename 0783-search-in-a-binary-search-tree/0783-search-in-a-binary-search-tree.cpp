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
    TreeNode* searchBST(TreeNode* root, int val) {
        // If empty tree or value found
        if (root == NULL || root->val == val)
            return root;
        else if (root->val > val)      // If value is smaller, go left
            return searchBST(root->left, val);
        else                           // If value is greater, go right
            return searchBST(root->right, val);
    }
};