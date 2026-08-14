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
    int lefth(TreeNode* node){
        int h =0;
        while(node){
            h++;
            node=node->left;
        }
        return h;
    }
    int righth(TreeNode* node){
        int h =0;
        while(node){
            h++;
            node=node->right;
        }
        return h;
    }
    int rec(TreeNode* node){
        if(!node)return 0;
        int lh = lefth(node);
        int rh = righth(node);
        if(lh==rh){
            int ans = (1<<lh)-1;
            return ans;
        }
        return 1+ rec(node->left)+rec(node->right);
    }
    int countNodes(TreeNode* root) {
        return rec(root);
    }
};