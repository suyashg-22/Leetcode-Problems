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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* a = new ListNode();
        ListNode* e = new ListNode();
        a->next = e;
        int ans = 0;
        while(temp!= NULL){
            ans+=temp->val; 
            if(temp->val==0){
                ListNode* abhi = temp;
                ListNode* agla = temp->next;
                ListNode* n = new ListNode(ans);
                ans=0;
                if(a->next==NULL){
                    a->next = n;
                    e=n;

                }
                else{
                    e->next = n;
                    e=n;
                }
            }

            temp=temp->next;
        }
        ListNode* z = a;
        a=a->next;
        z->next = NULL;
        delete z;

        return a->next;
    }
};