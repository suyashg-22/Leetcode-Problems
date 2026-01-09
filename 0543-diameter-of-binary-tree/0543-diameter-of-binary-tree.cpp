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


class Solution
{
public:
    unordered_map<TreeNode *, int> dp;
    int maxi = 0;

    int rec(TreeNode *node)
    {
        // pruning;

        // base case;
        if (!node)
        {
            return 0;
        }

        // cache check
        if (dp.count(node))
        {
            return dp[node];
        }

        // compute;
        int ans1 = 1 + rec(node->left);
        int ans2 = 1 + rec(node->right);
        int ans = max(ans1, ans2);

        // save and return;
        if (node->left && node->right)
        {
            maxi = max(maxi, ans1 + ans2 - 2);
        }
        else
        {
            maxi = (node->left)?max(maxi, ans1 - 1):max(maxi, ans2 - 1);
        }

        return dp[node]=ans;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {   rec(root);
        return maxi;
    }
};