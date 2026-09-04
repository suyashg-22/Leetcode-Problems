/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rev(ListNode* head){
        ListNode* node=head;
        ListNode* prev = NULL;
        while(node){
            ListNode* nxt = node->next;
            if(prev){
                node->next=prev;
            }
            else{
                node->next=NULL;
            }
            prev=node;
            node=nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head->next)return true;
        ListNode* l = head;
        ListNode* f = head;
        while(f->next && f->next->next){
            l=l->next;
            f=f->next->next;
        }
        ListNode* node1 = head;
        ListNode* node2 = l->next;
        l->next=NULL;
        node2= rev(node2);
        while(node1 && node2){
            if(node1->val !=node2->val)return false;
            node1=node1->next;
            node2=node2->next;
        }
        if(node1 && !node1->next)return true;
        if(node2 && !node2->next)return true;
        if(node1)return false;
        if(node2)return false;
        return true;
    }
};