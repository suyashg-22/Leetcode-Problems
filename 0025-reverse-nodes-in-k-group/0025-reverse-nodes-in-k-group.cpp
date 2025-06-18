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
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur){
            ListNode* frw = cur->next;
            cur->next = prev;
            prev= cur;
            cur=frw;
        }
        return prev;
    }
    ListNode* findkthnode(ListNode* head,int k){
        ListNode* temp = head;
        k-=1;
        while(k>0 && temp){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * temp = head;
        ListNode* kthnode;
        ListNode* nextnode;
        ListNode* prevnode;
        while(temp){
            kthnode = findkthnode(temp,k);
            if(!kthnode){
                if(prevnode){
                    prevnode->next = temp;
                }
                break;
            }
            nextnode=kthnode->next;
            kthnode->next=NULL;
            reverse(temp);
            if(temp==head){
                head=kthnode;
            }
            else{
                prevnode->next=kthnode;
            }
            prevnode=temp;
            temp=nextnode;
        }
        return head;
    }
};