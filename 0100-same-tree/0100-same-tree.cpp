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
    bool dfs(TreeNode* node1,TreeNode* node2){
        if(!node1 && !node2)return true;
        else if(node1 && !node2)return false;
        else if(!node1 && node2)return false;

        if(node1->val!=node2->val)return false;
        bool l = dfs(node1->left,node2->left);
        bool r = dfs(node1->right,node2->right);
        return (l&r);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q);
    }
};