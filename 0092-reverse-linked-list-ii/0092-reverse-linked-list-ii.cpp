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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)return head;
        int ind = 1;
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* last = NULL;

        // bool founda = false;
        // bool foundb = false;
        ListNode* l = NULL;
        ListNode* r = NULL;
        ListNode* cur = head;
        while (cur) {
            if (ind <= left) {
                if (ind == left) {
                    l = cur;
                    a = last;
                    if (a)
                        a->next = NULL;

                    last = cur;
                    cur = cur->next;
                    last->next = NULL;
                } else {
                    last = cur;
                    cur = cur->next;
                }
            } else if (ind <= right) {
                ListNode* temp = cur;
                ListNode* next = cur->next;
                cur = cur->next;
                temp->next = last;
                last = temp;

                if (ind == right) {
                    r = temp;
                    b = next;
                }
            } else {
                break;
            }
            ind += 1;
        }
        if (a && b) {
            a->next = r;
            l->next = b;
        } else if (a) {
            a->next = r;
        } else if(b){
            l->next = b;
            head=r;
        }else{
            head=r;
        }
        return head;
    }
};