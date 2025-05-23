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
    int fun(TreeNode* root,int& maxi){
        if(root==NULL) return 0;
        int ls = fun(root->left,maxi);
        int rs = fun(root->right,maxi);
        ls=max(0,ls);
        rs=max(0,rs);
        maxi = max(maxi,root->val+ls+rs);
        return root->val+max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        int maxi =INT_MIN;
        fun(root,maxi);
        return maxi;
    }
};