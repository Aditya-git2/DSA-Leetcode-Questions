/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to perform inorder traversal (left -> root -> Right)
    void postorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return; // base case
        // Step 1: Recursively traverse the left subtree
        postorder(root->left, ans);
        
        // Step 2: Recursively traverse the right subtree
       postorder(root->right, ans);
       // Step 3: Visit the current node (add its value to the answer)
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorder(root,ans);
        return ans;
    }
};