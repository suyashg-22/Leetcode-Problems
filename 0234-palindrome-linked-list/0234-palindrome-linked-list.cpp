class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        ListNode* prev = nullptr;

        // Find middle and reverse first half
        while(fast && fast->next){
            fast = fast->next->next;

            // Reverse first half on-the-fly
            ListNode* frw = slow->next;
            slow->next = prev;
            prev = slow;
            slow = frw;
        }

        // If odd length, skip middle node
        if(fast) slow = slow->next;

        // Compare reversed first half with second half
        while(prev && slow){
            if(prev->val != slow->val) return false;
            prev = prev->next;
            slow = slow->next;
        }

        return true;
    }
};
