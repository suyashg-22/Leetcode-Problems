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
    TreeNode* node ;
    TreeNode* head ;
    TreeNode* ans =NULL;
    void del(TreeNode* node,TreeNode* temp,TreeNode* templ,TreeNode*tempr,int dir){
        if(node==temp){
            head->left=NULL;
            head->right=NULL;
            if(!templ && !tempr){
                head=NULL;
                return;
            }
            else if(!templ){
                head=tempr;
            }
            else if(!tempr){
                head=templ;
            }
            else{
                head=tempr;
                while(tempr->left){
                    tempr=tempr->left;
                }
                tempr->left=templ;
            }
        }
        else{
            temp->left=NULL;
            temp->right=NULL;
            if(dir==0)node->left=NULL;
            else node->right=NULL;
            
            if(!templ && !tempr){
                return;
            }
            else if(!templ){
                if(dir==0)node->left=tempr;
                else node->right=tempr;
            }
            else if(!tempr){
                if(dir==0)node->left=templ;
                else node->right=templ;
            }
            else{
                TreeNode* consttr=tempr;
                while(tempr->left){
                    tempr=tempr->left;
                }
                tempr->left=templ;
                if(dir==0)node->left=consttr;
                else node->right=consttr;
            }
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        node =root;
        head = root;
        while(k--){
            if(!node->left){
                ans=node;
                del(node,node,node->left,node->right,-1);
                node=head;
            }
            else{
                while(node->left && node->left->left){
                    node=node->left;
                }
                ans=node->left;
                del(node,node->left,node->left->left,node->left->right,0);
                node=head;
            }
        }
        return ans->val;
    }
};