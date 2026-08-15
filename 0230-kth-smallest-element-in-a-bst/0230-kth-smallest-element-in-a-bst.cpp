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
    void rec(TreeNode* node,int& cnt,int k,int &ans){
        if(!node)return;
        rec(node->left,cnt,k,ans);
        cnt++;
        if(cnt==k)ans=node->val;
        rec(node->right,cnt,k,ans);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        int cnt=0;
        rec(root,cnt,k,ans);
        return ans;
    }
};