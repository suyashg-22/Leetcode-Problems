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
class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        TreeNode* node=root;
        while(node){
            st.push(node);
            node=node->left;
        }
    }
    
    int next() {
        if(st.empty())return -1;
        TreeNode* ans = st.top();
        st.pop();
        TreeNode* node=ans;
        if(node->right){
            node=node->right;
            while(node){
                st.push(node);
                node=node->left;
            }
        }
        return ans->val;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */