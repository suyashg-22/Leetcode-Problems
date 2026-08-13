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
    bool rec(TreeNode* node1 ,TreeNode* node2){
        if(!node1 && !node2)return true;
        else if(!node1 || !node2)return false;
        
        bool ans =rec(node1->left,node2->left);
        ans&= rec(node1->right,node2->right);
        if(!ans)return false;
        if(node1->val != node2->val)return false;
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return rec(p,q);
    }
};