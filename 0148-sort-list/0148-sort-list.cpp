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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        priority_queue<int,vector<int>,greater<int>>pq;
        ListNode* temp =head;
        ListNode* cur = head;
        while(temp){
            pq.push(temp->val);
            temp=temp->next;
        }
        while(!pq.empty()){
            cur->val = pq.top();
            pq.pop();
            cur=cur->next;
        }
        return head;
    }
};