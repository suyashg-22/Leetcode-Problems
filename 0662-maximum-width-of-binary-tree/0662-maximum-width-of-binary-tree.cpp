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
using ll = long long;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        ll maxi = 0;
        while(!q.empty()){
            ll size = q.size();
            ll base = q.front().second;
            ll l=-1;
            ll r=-1;
            for(int i=0;i<size;i++){
                auto it =q.front();
                q.pop();
                auto node = it.first;
                ll ind = it.second;
                ind-=base;
                if(i==0)l=ind;
                if(i==size-1)r=ind;
                if(node->left){
                    q.push({node->left,2*ind+1});
                }
                if(node->right){
                    q.push({node->right,2*ind+2});
                }
            }
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};