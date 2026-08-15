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
    TreeNode* del(TreeNode* node){
        TreeNode* l = node->left;
        TreeNode* r = node->right;
        if(!l && !r)return NULL;
        else if(!l)return r;
        else if(!r)return l;
        TreeNode*ll=l;
        while(ll->right)ll=ll->right;
        ll->right=r;
        return l;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        if(root->val==key){
            return del(root);
        }
        TreeNode* node= root;
        while(node){
            int x = node->val;
            if(x<key){
                if(node->right && node->right->val==key){
                    TreeNode* temp = del(node->right);
                    node->right = temp;
                    break;
                }
                node=node->right;
            }
            else{
                if(node->left && node->left->val==key){
                    TreeNode* temp=del(node->left);
                    node->left=temp;
                    break;
                }
                node=node->left;
            }
        }
        return root;
    }
};