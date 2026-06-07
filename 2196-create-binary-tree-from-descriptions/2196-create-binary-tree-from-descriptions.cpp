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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int,TreeNode*>mpp;
        unordered_map<int,int>mpp2;
        for(int i=0;i<n;i++){
            mpp2[descriptions[i][0]]=1;
            mpp2[descriptions[i][1]]=1;
        };
        
        for(int i=0;i<n;i++){
            int p = descriptions[i][0];
            int c = descriptions[i][1];
            bool l = descriptions[i][2];
            
            if(mpp2.count(c))mpp2.erase(c);

            if(mpp.count(p) && mpp.count(c)){
                TreeNode* pnode = mpp[p];
                TreeNode* cnode = mpp[c];
                if(l)pnode->left = cnode;
                else pnode->right = cnode;
            }
            else if(mpp.count(p)){
                TreeNode* pnode = mpp[p];
                TreeNode* node = new TreeNode(c);
                if(l)pnode->left = node;
                else pnode->right = node;
                mpp[c]=node;
            }
            else if(mpp.count(c)){
                TreeNode* pnode = new TreeNode(p);
                if(l)pnode->left = mpp[c];
                else pnode->right = mpp[c];
                mpp[p]=pnode;
            }
            else{
                TreeNode* pnode = new TreeNode(p);
                TreeNode* cnode = new TreeNode(c);
                if(l)pnode->left=cnode;
                else pnode->right=cnode;
                mpp[p]=pnode;
                mpp[c]=cnode;
            }
        }
        TreeNode* root = mpp[mpp2.begin()->first];
        return root;
    }
};