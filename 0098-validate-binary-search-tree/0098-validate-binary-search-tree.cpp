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
    bool rec(TreeNode * node,long long num1,long long num2){
        if(!node)return true;
        if(node->left && node->val <= node->left->val)return false;
        if(node->right && node->val >= node->right->val)return false;
        
        if(node->val <= num1 || node->val >=num2)return false;

        bool l = rec(node->left,num1,node->val);
        bool r = rec(node->right,node->val,num2);

        return (l&r);
    }
    bool isValidBST(TreeNode* root) {
        return rec(root,LONG_MIN,LONG_MAX);
    }
};