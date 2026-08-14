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
    void rec(TreeNode* node,vector<int>&ans,int l){
        if(!node)return;
        if(ans.size()==l){
            ans.push_back(node->val);
        }
        rec(node->right,ans,l+1);
        rec(node->left,ans,l+1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        rec(root,ans,0);
        return ans;
    }
};