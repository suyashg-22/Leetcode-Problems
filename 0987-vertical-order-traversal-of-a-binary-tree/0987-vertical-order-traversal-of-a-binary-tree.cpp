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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)return {};
        map<int,map<int,multiset<int>>>mpp;
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                auto it =q.front();
                q.pop();
                auto node = it.first;
                int r = it.second.first;
                int c = it.second.second;
                mpp[c][r].insert(node->val);
                if(node->left){
                    q.push({node->left,{r+1,c-1}});
                }
                if(node->right){
                    q.push({node->right,{r+1,c+1}});
                }
            }
        }
        for(auto it :mpp){
            int c = it.first;
            vector<int>temp;
            for(auto iit:it.second){
                int r = iit.first;
                for(auto node:iit.second){
                    temp.push_back(node);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};