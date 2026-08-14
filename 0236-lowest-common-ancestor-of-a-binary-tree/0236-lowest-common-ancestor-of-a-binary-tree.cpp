/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* rec(TreeNode* node,TreeNode* p,TreeNode* q){
        if(!node) return NULL;
        if(node==p || node==q)return node;

        TreeNode* l = rec(node->left,p,q);
        TreeNode* r = rec(node->right,p,q);
        if(l && r)return node;
        else if(r)return r;
        return l; 
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return rec(root,p,q);
    }
};