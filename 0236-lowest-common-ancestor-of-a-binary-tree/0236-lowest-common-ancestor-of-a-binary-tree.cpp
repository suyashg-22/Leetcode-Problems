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
    TreeNode* dfs(TreeNode* node,TreeNode*p,TreeNode* q){
        if(!node)return NULL;
        if(node==p || node==q)return node;
        TreeNode* l = dfs(node->left,p,q);
        TreeNode* r = dfs(node->right,p,q);
        if(!l && !r)return NULL;
        else if(!l)return r;
        else if(!r)return l;
        return node;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }
};