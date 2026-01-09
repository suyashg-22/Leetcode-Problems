class Solution {
public:
    int maxi = INT_MIN;

    int rec(TreeNode* node) {
        if(!node) return 0;

        int l = rec(node->left);
        int r = rec(node->right);

        int suml = max(node->val, node->val + l);
        int sumr = max(node->val, node->val + r);

        maxi = max(maxi, suml + sumr - node->val);

        return max(suml, sumr);
    }

    int maxPathSum(TreeNode* root) {
        rec(root);
        return maxi;
    }
};
