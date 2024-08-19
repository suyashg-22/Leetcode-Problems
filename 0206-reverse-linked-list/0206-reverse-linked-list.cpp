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
    
    ListNode* recur(ListNode* prev ,ListNode* cur){
        if(cur == NULL){
            return prev;
        }
        ListNode* forw = cur->next;
        cur->next=prev;
        prev = cur;
        cur = forw;
        return recur(prev,cur);  
    }
    ListNode* reverseList(ListNode* head) {
        return recur(NULL,head);
    }
};