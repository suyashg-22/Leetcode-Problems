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
    int maxh(TreeNode* node){
        if(!node)return 0;

        int ans= 1+maxh(node->left);
        ans = max(ans,1+maxh(node->right));
        return ans;
    }
    int maxDepth(TreeNode* root) {
        return maxh(root);
    }
};