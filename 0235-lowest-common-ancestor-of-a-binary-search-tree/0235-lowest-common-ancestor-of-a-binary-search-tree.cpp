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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node= root;
        if(!node)return NULL;
        TreeNode* ans=NULL;
        int mini = min(p->val,q->val);
        int maxi = max(p->val,q->val);
        while(node){
            int x =node->val;
            if(node==p ||node==q){
                ans=node;
                break;
            }
            else if(x<mini){
                node=node->right;
            }
            else if(maxi<x){
                node=node->left;
            }
            else{
                ans = node;
                break;
            }
        }
        return ans;
    }
};