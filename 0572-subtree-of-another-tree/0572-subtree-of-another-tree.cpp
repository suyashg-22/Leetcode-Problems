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
    bool ans = false;
    bool check(TreeNode*n1 , TreeNode*n2){
        if(!n1 && !n2)return true;
        if(!n1)return false;
        if(!n2)return false;

        if(n1->val!=n2->val)return false;
        bool res1= check(n1->left,n2->left);
        bool res2= check(n1->right,n2->right);
        if(res1 && res2)return true;
        return false;
    }
    void dfs(TreeNode* node,TreeNode* subroot){
        if(!node)return;
        if(node->val == subroot->val){
            if(check(node,subroot)){
                ans=true;
                return;
            }
        }
        dfs(node->left,subroot);
        dfs(node->right,subroot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        dfs(root,subRoot);
        return ans;
    }
};