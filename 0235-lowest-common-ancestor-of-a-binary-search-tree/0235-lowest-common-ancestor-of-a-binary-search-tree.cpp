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
        TreeNode* node = root;
        int mini = min(p->val,q->val);
        int maxi = max(p->val,q->val);
        TreeNode* ans= NULL;
        while(node){
            int x = node->val;
            if(node==p || node==q){
                ans=node;
                break;
            }
            else if(mini<x && x<maxi){
                ans=node;
                break;
            }
            else if(maxi<x)node=node->left;
            else node=node->right;
        }
        return ans;
    }
};