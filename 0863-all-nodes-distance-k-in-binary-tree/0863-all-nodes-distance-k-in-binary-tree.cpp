/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node,TreeNode* p,unordered_map<TreeNode*,TreeNode*>&mpp){
        if(!node)return;
        if(p)mpp[node]=p;
        dfs(node->left,node,mpp);
        dfs(node->right,node,mpp);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root)return {};
        vector<int>ans;
        unordered_map<TreeNode*,TreeNode*>mpp;
        unordered_map<TreeNode*,bool>vis;
        dfs(root,NULL,mpp);
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=1;
        int d=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node =q.front();
                q.pop();
                if(d==k){
                    ans.push_back(node->val);
                }
                else if(d<k){
                    if(node->left && !vis.count(node->left)){
                        q.push(node->left);
                        vis[node->left]=1;
                    }
                    if(node->right && !vis.count(node->right)){
                        q.push(node->right);
                        vis[node->right]=1;
                    }
                    if(mpp.count(node) && !vis.count(mpp[node])){
                        q.push(mpp[node]);
                        vis[mpp[node]]=1;
                    }
                }
            }
            d++;
        }
        return ans;
    }
};