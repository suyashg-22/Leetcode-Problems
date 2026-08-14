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
    void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mpp){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto node =q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    mpp[node->left]=node;
                }
                if(node->right){
                    q.push(node->right);
                    mpp[node->right]=node;
                }
            }
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0)return{target->val};
        unordered_map<TreeNode*,TreeNode*>mpp;
        parent(root,mpp);

        vector<int>ans;
        queue<TreeNode*>q;
        q.push(target);
        int d=1;
        unordered_map<TreeNode*,int>vis;
        vis[target]=1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();
                if(node->left && !vis.count(node->left)){
                    q.push(node->left);
                    vis[node->left]=1;
                    if(d==k)ans.push_back(node->left->val);
                }
                if(node->right && !vis.count(node->right)){
                    q.push(node->right);
                    vis[node->right]=1;
                    if(d==k)ans.push_back(node->right->val);
                }
                if(mpp.count(node) && !vis.count(mpp[node])){
                    q.push(mpp[node]);
                    vis[mpp[node]]=1;
                    if(d==k)ans.push_back(mpp[node]->val);
                }
            }
            d++;
            if(d>k)break;
        }
        return ans;
    }
};