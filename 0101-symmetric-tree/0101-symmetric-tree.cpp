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
    bool f(TreeNode* n1,TreeNode* n2){
        if(!n1 && !n2)return true;
        if((!n1 && n2)||(n1 && !n2))return false;
        if(n1->val != n2->val)return false;

        bool temp1 = f(n1->left,n2->right);
        if(!temp1)return false;
        bool temp2 = f(n1->right,n2->left);
        if(!temp2)return false;

        return true;
    }
    bool isSymmetric(TreeNode* root) {
       return  f(root->left,root->right);
    }
};