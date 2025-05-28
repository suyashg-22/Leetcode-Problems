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
    void parent(TreeNode*root,TreeNode* target,unordered_map<TreeNode*,TreeNode*>&parentmpp){
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode * cur = q.front();
            q.pop();

            if(cur->left){
                q.push(cur->left);
                parentmpp[cur->left]=cur;
            } 
                
            if(cur->right){
                q.push(cur->right);
                parentmpp[cur->right]=cur;
            } 
        }        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parentmpp;
        parent(root,target,parentmpp);

        unordered_map<TreeNode*,bool>visitedmpp;
        queue<TreeNode*>q;
        q.push(target);
        visitedmpp[target]=true;
        int curlevel =0;
        while(!q.empty()){
            int size = q.size();
            if(curlevel++ == k) break;
            for(int i =0;i<size;i++){
                TreeNode* cur =q.front();
                q.pop();
                if(cur->left && !visitedmpp[cur->left]){
                    visitedmpp[cur->left]=true;
                    q.push(cur->left);
                }
                if(cur->right && !visitedmpp[cur->right]){
                    visitedmpp[cur->right]=true;
                    q.push(cur->right);
                }
                if(parentmpp[cur] && !visitedmpp[parentmpp[cur]]){
                    visitedmpp[parentmpp[cur]]=true;
                    q.push(parentmpp[cur]);
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            ans.push_back(cur->val);
        }
        return ans;
    }
};