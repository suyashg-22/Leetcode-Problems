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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode * newnode = new TreeNode(val);
            return newnode;
        }

        TreeNode* node = root;
        TreeNode* cur =root;
        bool l =false;
        bool r =false;
        while(root){
            if(root->val>val){
                cur=root;
                root=root->left;
                l = true;
                r = false;
            }
            else{
                cur=root;
                root=root->right;
                r = true;
                l = false;  
            }    
        }
        TreeNode * newnode = new TreeNode(val);
        if(r){
            cur->right = newnode;
        }
        else cur->left = newnode;

        return node;
    }
};