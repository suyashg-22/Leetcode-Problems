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
    int dfs(TreeNode* node,int &maxi){
        int l = (node->left)?dfs(node->left,maxi):-1e9;
        int r = (node->right)?dfs(node->right,maxi):-1e9;
        maxi= max({maxi,l,r,node->val,l+r+node->val,l+node->val,r+node->val});
        return max({node->val,l+node->val,r+node->val});
    }
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        int maxi=-1e9;
        dfs(root,maxi);
        return maxi;
    }
};