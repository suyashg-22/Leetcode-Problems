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
    int cnt =0;
    int level =0;
    void rec(TreeNode* node,int l){
        if(l==level-1){
            cnt+=1;
            return;
        }
        if(node->left)rec(node->left,l+1);
        if(node->right)rec(node->right,l+1);
    }

    int countNodes(TreeNode* root) {
       TreeNode * node = root;
       while(node){
            level+=1;
            node=node->left;
        }
        if(!root)return 0;
        cnt= (1<<(level-1))-1;
        rec(root,0);
        return cnt;
    }
};