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
class BSTIterator
{
public:
    TreeNode *node = NULL;
    stack<TreeNode *> st;

    BSTIterator(TreeNode *root)
    {
        node = root;
        while (node->left)
        {
            st.push(node);
            node = node->left;
        }
    }

    int next()
    {
        if (node)
        {
            int ans = node->val;
            if (node->right)
            {
                node = node->right;
                while (node->left)
                {
                    st.push(node);
                    node = node->left;
                }
            }
            else
            {
                if (st.empty())
                {
                    node = NULL;
                }
                else
                {
                    node = st.top();
                    st.pop();
                }
            }
            return ans;
        }
        return -1;
    }

    bool hasNext()
    {
        if (node)
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */