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

struct node{
    bool flag;
    int sum;
    int mini;
    int maxi;
};

class Solution {
public:

    node rec(TreeNode* cur,int &ans){
        if(!cur)return{true,0,INT_MAX,INT_MIN};
        node l =rec(cur->left,ans);
        node r =rec(cur->right,ans);
        if(l.flag && r.flag && l.maxi<cur->val && cur->val<r.mini){
            int s = l.sum+r.sum+cur->val;
            ans=max(ans,s);
            return {true,s,min(l.mini,cur->val),max(r.maxi,cur->val)};
        }
        return {false,0,0,0};
    }

    int maxSumBST(TreeNode* root) {
        int ans= 0;
        rec(root,ans);
        return ans;
    }
};