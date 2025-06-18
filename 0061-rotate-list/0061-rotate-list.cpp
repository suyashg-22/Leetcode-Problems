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
    ListNode* findnewtail(ListNode * temp,int cnt){
        cnt-=1;
        while(cnt>0 && temp){
            cnt-=1;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int len =1;
        ListNode * tail = head;
        ListNode * temp = head;
        while(tail->next){
            len+=1;
            tail=tail->next;
        }
        if(k%len==0) return head;
        int cnt = len-(k%len);
        ListNode* newtail = findnewtail(temp,cnt);
        tail->next=head;
        head= newtail->next;
        newtail->next = NULL;
        return head;
    }
};