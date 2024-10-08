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
    int hcf(int a,int b){
        int ans =0;
        for(int i=1;i<=min(a,b);i++){
            if(a%i==0 && b%i==0){
                ans=i;
            }
        }
        return ans;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp= head;
        while(temp !=NULL){
            ListNode* cur = temp;
            if(temp->next==NULL){
                break;
            }
            ListNode* agla = temp->next;
            int a = temp->val;
            int b = (temp->next)->val;
            int ans = hcf(a,b);
            ListNode* newnode= new ListNode(ans);
            cur->next = newnode;
            newnode->next = agla;
            temp = agla;
        }
        return head;
    }
};