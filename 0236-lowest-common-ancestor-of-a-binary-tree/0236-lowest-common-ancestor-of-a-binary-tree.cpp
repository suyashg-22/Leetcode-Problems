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
    TreeNode* P = NULL;
    TreeNode* Q = NULL;
    TreeNode* ans = NULL;
    TreeNode* overlap =NULL;

    TreeNode* rec(TreeNode* node){
        if(!node)return NULL;
        if(node==P || node==Q){
            overlap = node;
            return node;
        }


        TreeNode* l = rec(node->left);
        TreeNode* r = rec(node->right);

        if(l && r){
            ans = node;
        }
        
        if(!l)return r;
        return l;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        P=p;
        Q=q;
        rec(root);
        if(!ans)return overlap;
        return ans;
    }
};