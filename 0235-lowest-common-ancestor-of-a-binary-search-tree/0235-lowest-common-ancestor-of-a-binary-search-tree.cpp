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
        if(!node)return NULL;
        if(node==p || node==q)return node;
        int mini = min(p->val,q->val);
        int maxi = max(p->val,q->val);
        int x = node->val;
        if(mini<x && x<maxi)return node;
        else if(maxi<x) return rec(node->left,p,q);
        return rec(node->right,p,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return rec(root,p,q);
    }
};