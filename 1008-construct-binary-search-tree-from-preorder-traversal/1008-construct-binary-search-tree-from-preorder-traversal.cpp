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
    TreeNode* rec(int& level,int u,vector<int>&arr,int n){
        if(level>=n)return NULL;
        int x = arr[level];
        if(x>=u)return NULL;
        TreeNode* temp = new TreeNode(x);
        level++;
        temp->left= rec(level,x,arr,n);
        temp->right= rec(level,u,arr,n);
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        int level=0;
        return rec(level,1e9,preorder,n);
    }
};