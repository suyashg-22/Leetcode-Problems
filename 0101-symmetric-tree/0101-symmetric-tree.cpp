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
    bool rec(TreeNode* p,TreeNode* q){
        if(!p && !q)return true;
        else if(!p || !q)return false;
        else if(p->val != q->val)return false;

        bool ans = rec(p->left,q->right);
        ans &= rec(p->right,q->left);
        return ans;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return rec(root->left,root->right);
    }
};