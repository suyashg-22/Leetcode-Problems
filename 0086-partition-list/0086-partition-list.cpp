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
    ListNode* partition(ListNode* head, int x) {
        ListNode* shead = NULL;
        ListNode* small = NULL;

        ListNode* last = NULL;
        ListNode* cur = head;
        ListNode* head2 = NULL;

        while (cur) {
            if (cur->val < x) {
                ListNode* temp = cur;
                cur = cur->next;
                temp->next = NULL;
                if(last)last->next = cur;
                if (!small) {
                    shead = temp;
                    small = temp;
                }
                else {
                    small->next = temp;
                    small = small->next;
                }
            }
            else{
                last=cur;
                cur=cur->next;
                if(!head2)head2=last;
            }
        }

        if(!small)return head2;
        if(!head2)return shead;
        small->next=head2;
        return shead;
    }
};