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
    void f(TreeNode* root,TreeNode*p,TreeNode*q,TreeNode * & ans){
        if(!root) return;

        while(true){
            if((root->val > p->val && root->val <q->val)||(root->val > q->val && root->val <p->val)){
                ans =root;
                break;
            }
            else if(root->val == p->val || root->val==q->val){
                ans =root;
                break;
            }
            else if(root->val > p->val && root->val > q->val){
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * ans = root;
        f(root,p,q,ans);
        return ans;
    }
};
