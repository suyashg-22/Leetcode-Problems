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
    void rec(TreeNode* node){
        if(!node)return;

        rec(node->left);
        rec(node->right);
        TreeNode* l = node->left;
        TreeNode* r = node->right;
        node->left=r;
        node->right=l;
    }
    TreeNode* invertTree(TreeNode* root) {
        rec(root);
        return root;
    }
};