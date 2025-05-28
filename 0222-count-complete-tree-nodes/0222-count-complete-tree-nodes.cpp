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
    int heightleft(TreeNode* root){
        int ans =0;
        while(root){
            ans+=1;
            root=root->left;
        }
        return ans;

    }
    int heightright(TreeNode* root){
        int ans =0;
        while(root){
            ans+=1;
            root=root->right;
        }
        return ans;

    }
    int f(TreeNode*root){
        if(!root) return 0;
        
        int lh =heightleft(root);
        int rh =heightright(root);

        if(lh == rh) return (1<<lh)-1;
        return 1+f(root->left)+f(root->right);
        
    }
    int countNodes(TreeNode* root) {
        int count = f(root);
        return count;
    }
};