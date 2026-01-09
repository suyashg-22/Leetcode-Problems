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
        queue<pair<int,pair<int,TreeNode*>>>q;
        q.push({0,{0,root}});

        while(!q.empty()){
            auto it = q.front();
            int x = it.first;
            int y = it.second.first;
            TreeNode* node = it.second.second;
            q.pop();
            mpp[x][y].insert(node->val);

            if(node->left){
                q.push({x-1,{y+1,node->left}});
            }
            if(node->right){
                q.push({x+1,{y+1,node->right}});
            }
        }
        vector<vector<int>>ans;
        for(auto it:mpp){
            vector<int>temp;
            for(auto iit:it.second){
                for(auto val:iit.second){
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};