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
        TreeNode* head = root;
        TreeNode* node = root;
        TreeNode* temp = new TreeNode(val);
        if(!node){
            return temp;
        }
        while(node){
            if(node->val>val){
                if(!node->left){
                    node->left=temp;
                    break;
                }
                node=node->left;
            }
            else {
                if(!node->right){
                    node->right=temp;
                    break;
                }
                node=node->right;
            }
        }
        return head;
    }
};