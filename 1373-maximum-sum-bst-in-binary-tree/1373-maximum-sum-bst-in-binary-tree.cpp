class Solution {
public:
    int ans = 0;

    struct node {
        bool bst;
        int sum;
        int mn;
        int mx;
    };

    node dfs(TreeNode* u) {
        if (!u)
            return {true, 0, INT_MAX, INT_MIN};

        auto l = dfs(u->left);
        auto r = dfs(u->right);

        if (l.bst && r.bst && l.mx < u->val && u->val < r.mn) {
            int s = l.sum + r.sum + u->val;
            ans = max(ans, s);

            return {
                true,
                s,
                min(l.mn, u->val),
                max(r.mx, u->val)
            };
        }

        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
