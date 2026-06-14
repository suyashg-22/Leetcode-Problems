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
    int pairSum(ListNode* head) {
        ListNode*s=head;
        ListNode*f=head;
        while(s->next && f->next && f->next->next){
            s=s->next;
            f=f->next->next;
        }
        if(!s->next)return s->val;
        ListNode*node=s->next;
        s->next=NULL;
        ListNode*last=NULL;
        while(node){
            ListNode* nxt = node->next;
            if(!last){
                node->next = NULL;
                last=node;
                node=nxt;
            }
            else{
                node->next=last;
                last=node;
                node=nxt;
            }
        }
        ListNode*node1=head;
        ListNode*node2=last;
        int maxi=0;
        while(node1 && node2){
            maxi=max(node1->val+node2->val,maxi);
            node1=node1->next;
            node2=node2->next;
        }
        return maxi;
    }
};