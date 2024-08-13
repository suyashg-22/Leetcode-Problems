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
    ListNode* removeElements(ListNode* head, int val) {
        // Handle the case where the head node itself needs to be removed
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp; // Free memory of the removed node
        }
        
        // If the list becomes empty after removing nodes, return nullptr
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode* current = head;
        
        // Traverse the list and remove nodes with the specified value
        while (current != nullptr && current->next != nullptr) {
            if (current->next->val == val) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp; // Free memory of the removed node
            } else {
                current = current->next; // Move to the next node
            }
        }
        
        return head;
    }
};
