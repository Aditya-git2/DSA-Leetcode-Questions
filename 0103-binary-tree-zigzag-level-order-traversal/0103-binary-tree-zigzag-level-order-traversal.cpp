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
    int levels(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    void nthLevelOrder(TreeNode* root, int curr, int level, vector<int>& v) {
        if (root == NULL)
            return;
        if (curr == level) {
            v.push_back(root->val);
            return;
        }
        nthLevelOrder(root->left, curr + 1, level, v);
        nthLevelOrder(root->right, curr + 1, level, v);
    }
    void nthLevelOrderReverse(TreeNode* root, int curr, int level, vector<int>& v) {
        if (root == NULL)
            return;
        if (curr == level) {
            v.push_back(root->val);
            return;
        }
        nthLevelOrderReverse(root->right, curr + 1, level, v);
        nthLevelOrderReverse(root->left, curr + 1, level, v);
    }
    void levOrder(TreeNode* root, vector<vector<int>>& ans) {
        int n = levels(root);
        for (int i = 1; i <= n; i++) { // for level
            vector<int> v;
            if(i%2 == 0){
                nthLevelOrderReverse(root, 1, i, v);
            }
            else{
                nthLevelOrder(root, 1, i, v);
            }
            
            ans.push_back(v);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levOrder(root, ans);
        return ans;
    }
};