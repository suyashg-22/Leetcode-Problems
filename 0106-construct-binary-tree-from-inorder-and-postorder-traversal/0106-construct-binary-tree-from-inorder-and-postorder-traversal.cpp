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
    TreeNode* f(vector<int>& postorder,int poststart,int postend, vector<int>& inorder,int instart,int inend,unordered_map<int,int>&mpp){
        if(poststart>postend || instart>inend) return NULL;

        TreeNode* root = new TreeNode(postorder[postend]);
        int inroot = mpp[postorder[postend]];
        int numsleft = inroot-instart;

        root->left = f(postorder,poststart,poststart+numsleft-1,inorder,instart,inroot-1,mpp);
        root->right = f(postorder,poststart+numsleft,postend-1,inorder,inroot+1,inend,mpp);
        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mpp;
        int n = postorder.size();
        int m = inorder.size();
        if(n!=m )return NULL;
        for(int i=0;i<m;i++){
            mpp[inorder[i]]=i;
        }

        TreeNode* root = f(postorder,0,n-1,inorder,0,m-1,mpp);
        return root;
    }
};