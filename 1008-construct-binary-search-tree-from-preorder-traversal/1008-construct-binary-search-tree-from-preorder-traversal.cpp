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
    int n=0;
    vector<int> *arr;
    int i=0;

    TreeNode * build(int limit){
        if(i>=n || (*arr)[i]>limit)return NULL;
        TreeNode* node = new TreeNode((*arr)[i]);
        i+=1;
        node->left=build((*arr)[i-1]);
        node->right=build(limit);

        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        arr=&preorder;
        n=preorder.size();
        return build(INT_MAX);
    }
};