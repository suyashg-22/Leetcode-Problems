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
            TreeNode* nnode = new TreeNode(val);
            return nnode;
        }
        TreeNode* node =root;
        while(node){
            int x = node->val;
            if(x<val){
                if(node->right)node=node->right;
                else{
                    TreeNode* nnode = new TreeNode(val);
                    node->right = nnode;
                    break;
                }
            }
            else{
                if(node->left)node=node->left;
                else{
                    TreeNode* nnode = new TreeNode(val);
                    node->left=nnode;
                    break;
                }
            }
        }
        return root;
    }
};