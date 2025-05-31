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
    void f(TreeNode* root,int k,int &cnt,int &ans){
        if(!root) return;

        f(root->left,k,cnt,ans);
        cnt+=1;
        if(cnt==k) {
            ans = root->val;
            return;
        }
        f(root->right,k,cnt,ans);
    }
    int kthSmallest(TreeNode* root, int k) {

        int cnt =0;
        int ans = -1;
        f(root,k,cnt,ans);
        return ans;
    }
};