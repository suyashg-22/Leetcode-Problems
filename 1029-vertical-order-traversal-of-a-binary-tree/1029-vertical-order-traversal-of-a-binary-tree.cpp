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
        map<int,map<int,multiset<int>>>mpp;
        queue<pair<TreeNode *,pair<int,int>>>Q;
        Q.push({root,{0,0}});
        while(!Q.empty()){
            auto p = Q.front();
            TreeNode* node= p.first;
            Q.pop();
            int x = p.second.first;
            int y = p.second.second;
            mpp[x][y].insert(node->val);
            if(node->left) Q.push({node->left,{x-1,y+1}});
            if(node->right) Q.push({node->right,{x+1,y+1}});
        } 
        vector<vector<int>>ans;
        for(auto p:mpp){
            vector<int>temp;
            for(auto q:p.second){
                temp.insert(temp.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};