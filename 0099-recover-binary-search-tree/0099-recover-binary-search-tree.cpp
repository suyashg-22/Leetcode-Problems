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
    TreeNode* prev=NULL;
    void rec(TreeNode* node,TreeNode* &f,TreeNode* &s,TreeNode* &t){
        if(!node)return;
        rec(node->left,f,s,t);

        if(prev && prev->val>node->val){
            if(s){
                t=node;
            }
            else{
                f=prev;
                s=node;
            }
        }
        prev=node;

        rec(node->right,f,s,t);
    }
    void recoverTree(TreeNode* root) {
        TreeNode*f=NULL;
        TreeNode*s=NULL;
        TreeNode*t=NULL;
        rec(root,f,s,t);
        if(!t){
            swap(f->val,s->val);
        }
        else{
            swap(f->val,t->val);
        }
    }
};