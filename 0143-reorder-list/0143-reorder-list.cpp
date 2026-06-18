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
    ListNode* reverselist(ListNode* node){
        ListNode* last =NULL;
        while(node){
            ListNode* nxt =node->next;
            if(!last){
                node->next=NULL;
                last=node;
                node=nxt;
            }
            else{
                node->next=last;
                last=node;
                node=nxt;
            }
        }
        return last;
    }
    void reorderList(ListNode* head) {
        if(!head->next)return;
        ListNode* s =head;
        ListNode* f =head;
        while(s->next && f->next && f->next->next){
            s=s->next;
            f=f->next->next;
        } 
        ListNode* temp=s->next;
        s->next=NULL;
        ListNode* n2 = reverselist(temp);
        ListNode* n1 = head;
        while(n1 && n2){
                ListNode* n1nxt = n1->next;
                ListNode* n2nxt = n2->next;
                n2->next=NULL;
                n1->next=NULL;
                n1->next=n2;
                n2->next=n1nxt;
                n1=n1nxt;
                n2=n2nxt;
        }
    }
};