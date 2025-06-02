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
class BSTiterator {
private:
    stack<TreeNode*>st;
    bool reverse=true;
    void pushall(TreeNode* root){
        while(root){
            st.push(root);
            if(reverse){
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
    }
public:
    BSTiterator(TreeNode* root,bool reverse){
        this->reverse = reverse;
        pushall(root);
    }
    bool isnext(){
        return !st.empty();
    }
    int next(){
        TreeNode * temp = st.top();
        st.pop();
        if(!reverse) pushall(temp->right);
        else pushall(temp->left);
        return temp->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTiterator l(root,false);
        BSTiterator r(root,true);
        
        int i = l.next();
        int j = r.next();
        while(i<j){
            if( i+j == k) return true;
            else if(i+j >k){
                j= r.next();
            }
            else i = l.next();
        }
        return false;
    }
};