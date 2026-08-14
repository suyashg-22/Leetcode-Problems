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
    TreeNode* build(vector<int>&pre,int prestart,int preend,vector<int>&ino,int inostart,int inoend,unordered_map<int,int>&mpp){
        if(prestart>preend||inostart>inoend)return NULL;
        
        TreeNode* root = new TreeNode(pre[prestart]);
        int inoroot = mpp[pre[prestart]];
        int inoleft = inoroot-inostart;
        root->left = build(pre,prestart+1,prestart+inoleft,ino,inostart,inoroot-1,mpp);
        root->right = build(pre,prestart+inoleft+1,preend,ino,inoroot+1,inoend,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        int n= preorder.size();
        int m= inorder.size();
        for(int i=0;i<m;i++)mpp[inorder[i]]=i;
        return build(preorder,0,n-1,inorder,0,m-1,mpp);
    }
};