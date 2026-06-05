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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n = lists.size();
        for(int i=0;i<n;i++){
            ListNode * temp = lists[i];
            while(temp){
                pq.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode* head = NULL;
        ListNode* temp = NULL;
        while(!pq.empty()){
            ListNode* node = new ListNode(pq.top());
            pq.pop();
            if(!head){
                head= node;
                temp= node;
            }
            else{
                temp->next = node;
                temp=temp->next;
            }
        }
        return head;
    }
};