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
    void dfs(TreeNode* node,int x,int y,map<int,map<int,multiset<int>>>&mpp){
        if(!node)return;
        mpp[x][y].insert(node->val);
        dfs(node->left,x-1,y+1,mpp);
        dfs(node->right,x+1,y+1,mpp);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)return {};
        map<int,map<int,multiset<int>>>mpp;
        dfs(root,0,0,mpp);

        vector<vector<int>>ans;
        for(auto it :mpp){
            vector<int>temp;
            int x = it.first;
            for(auto jt:it.second){
                int y = jt.first;
                for(auto val:jt.second){
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};