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
    TreeNode* head=NULL;
    int K;
   bool find(TreeNode* notnode, int x){
    TreeNode* node = head;
    while(node){
        if(node->val == x){
            if(node != notnode) return true;
            // same node → must continue search
            node = node->right;  // or left, depending on duplicates rule
        }
        else if(node->val > x){
            node = node->left;
        }
        else{
            node = node->right;
        }
    }
    return false;
}

    bool fun(TreeNode* node){
        if(!node)return false;

        int req = K-node->val;
        if(find(node,req)) return true;

        bool l = fun(node->left);
        bool r = fun(node->right);
        return (l|r);
    }
    bool findTarget(TreeNode* root, int k) {
        head = root;
        K=k;
        return fun(root);
    }
};