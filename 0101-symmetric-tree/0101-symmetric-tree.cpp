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
    bool f(TreeNode* left,TreeNode* right){
        if(left == NULL || right==NULL){
            return left==right;
        }
        if(left->val != right->val) return false;

        bool l=f(left->left,right->right);
        bool r=f(left->right,right->left);
        if(l==true && r== true){
            return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        return f(root->left,root->right);
    }
};