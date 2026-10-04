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
    TreeNode* adjust(TreeNode* node){
        TreeNode* l = node->left;
        TreeNode* r = node->right;
        if(!l && !r) return NULL;
        else if(!l) return r;
        else if(!r) return l;

        TreeNode* temp= r;
        while(temp){
            if(temp->left)temp=temp->left;
            else break;
        }
        temp->left=l;
        return r;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        if(root->val == key){
            return adjust(root);
        }
        TreeNode* node =root;
        while(node){
            int x = node->val;
            if(x<key){
                if(node->right && node->right->val==key){
                    node->right=adjust(node->right);
                    break;
                }
                else node=node->right;
            }
            else{
                if(node->left && node->left->val==key){
                    node->left=adjust(node->left);
                    break;
                }
                else node=node->left;
            }
        }
        return root;
    }
};