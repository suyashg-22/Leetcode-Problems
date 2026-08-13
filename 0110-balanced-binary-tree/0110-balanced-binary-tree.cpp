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
    int rec(TreeNode* node,bool& ans){
        if(!node)return 0;
        int l = rec(node->left,ans);
        int r = rec(node->right,ans);
        if(abs(l-r)>1)ans=false;
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        bool ans=  true;
        rec(root,ans);
        return ans;
    }
};