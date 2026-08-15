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
            TreeNode* temp= new TreeNode(val);
            return temp;
        }
        TreeNode* node =root;
        while(node){
            int x = node->val;
            if(x<val){
                if(!node->right){
                    TreeNode* temp= new TreeNode(val);
                    node->right=temp;
                    break;
                }
                else{
                    node=node->right;
                }
            }
            else{
                if(!node->left){
                    TreeNode* temp= new TreeNode(val);
                    node->left=temp;
                    break;
                }
                else{
                    node=node->left;
                }
            }
        }
        return root;
    }
};