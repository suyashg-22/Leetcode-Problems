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
    int ans =0;
    void dfs(TreeNode* node,int maxi){
        if(!node)return;

        if(node->val>=maxi){
            ans+=1;
            dfs(node->left,node->val);
            dfs(node->right,node->val);
        }
        else{
            dfs(node->left,maxi);
            dfs(node->right,maxi);
        }
    }
    int goodNodes(TreeNode* root) {
        dfs(root,-1e9);
        return ans;
    }
};