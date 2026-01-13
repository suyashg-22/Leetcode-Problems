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
    TreeNode* prev = NULL;
    TreeNode* fault1 = NULL;
    TreeNode* temp = NULL;
    TreeNode* fault2 = NULL;

    void rec(TreeNode* node){
        if(!node)return;

        rec(node->left);
        if(prev){
            if(!fault1){
                if(node->val<prev->val){
                    fault1=prev;
                    temp = node;
                }
            }
            else{
                if(node->val<prev->val){
                    fault2=node;
                }
            }
        }
        prev=node;
        rec(node->right);

    }
    void recoverTree(TreeNode* root) {
        TreeNode* node = root;
        rec(node);
        if(!fault2){
            fault2=temp;
        }
        swap(fault1->val,fault2->val);
    }
};