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
    bool rec(TreeNode* node,long long l,long long r){
        if(!node)return true;
        if(node->val<=l || node->val>=r)return false;
        bool ans = rec(node->left,l,node->val);
        ans&=rec(node->right,node->val,r);
        return ans;
    }
    bool isValidBST(TreeNode* root) {
        return rec(root,LONG_MIN,LONG_MAX);
    }
};