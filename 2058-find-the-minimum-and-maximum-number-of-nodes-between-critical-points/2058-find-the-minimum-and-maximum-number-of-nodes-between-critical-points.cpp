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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* node = head;
        ListNode* prev = NULL;
        int d=0;
        int last=-1;
        int mini=INT_MAX;
        int f=-1;
        int l=-1;
        while(node){
            if(prev && node->next){
                int p = prev->val;
                int c = node->val;
                int n = node->next->val;
                if((c>p && c>n)||(c<p && c<n)){
                    if(last!=-1){
                        mini=min(mini,d-last);
                    }
                    last=d;
                    if(f==-1)f=d;
                    l=d;
                }
            }
            prev=node;
            node=node->next;
            d++;
        }
        if(f==l)return {-1,-1};
        return {mini,l-f};
    }
};