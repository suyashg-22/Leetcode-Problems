/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *node = root;
        TreeNode *ans = NULL;
        while (node)
        {
            if (node == p || node == q)
            {
                ans=node;
                break;
            }
            else if ((p->val < node->val && node->val < q->val) || (q->val < node->val && node->val < p->val))
            {
                ans=node;
                break;
            }
            else{
                if(node->val>p->val && node->val>q->val){
                    node=node->left;
                }
                else{
                    node=node->right;
                }
            }
        }
        return ans;
    }
};