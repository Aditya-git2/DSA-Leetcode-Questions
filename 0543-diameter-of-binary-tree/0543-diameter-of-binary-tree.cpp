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
    int levels(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    void helper(TreeNode* root, int &maxDia) {
        if (root == NULL) return;
        int dia = levels(root->left) + levels(root->right);
        maxDia = max(maxDia, dia);
        // visit each node to check its perspective
        helper(root->left,maxDia);
        helper(root->right,maxDia);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        helper(root,maxDia);
        return maxDia;
    }
};

// class Solution {
// public:
//     // Interviewer does not allow to use global variable
//     int maxDia = 0;      // global variable
//     int levels(TreeNode* root) {
//         if (root == NULL)
//             return 0;
//         return 1 + max(levels(root->left), levels(root->right));
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if (root == NULL)
//             return 0;
//         int dia = levels(root->left) + levels(root->right);
//         maxDia = max(maxDia, dia);
//         // visit each node to check its perspective
//         diameterOfBinaryTree(root->left);
//         diameterOfBinaryTree(root->right);
//         return maxDia;
//     }
// };