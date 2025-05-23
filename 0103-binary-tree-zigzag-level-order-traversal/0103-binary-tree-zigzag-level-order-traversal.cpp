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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        int i=0;
        while(!q.empty()){
            vector<int>level;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* root = q.front();
                q.pop();
                if(root->left != NULL) q.push(root->left);
                if(root->right != NULL) q.push(root->right);
                level.push_back(root->val);
            }
            if(i%2==0) ans.push_back(level);
            else{
                reverse(level.begin(),level.end());
                ans.push_back(level);
            }
            i+=1;
        }
        return ans;
    }
};