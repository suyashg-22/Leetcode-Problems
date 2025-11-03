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
class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        int n = nums.size();
        unordered_map<int, bool> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]] = true;
        }
        bool flag = false;
        ListNode *prev = NULL;
        ListNode *temp = head;
        ListNode *start = NULL;
        while (temp->next)
        {

            if (mpp[temp->val])
            {
                ListNode *alpha = temp;
                temp = temp->next;
                (prev) ? prev->next = temp : prev = NULL;
                alpha->next = NULL;
            }
            else
            {
                if (!flag)
                {
                    start = temp;
                    temp = temp->next;
                    prev = start;
                    flag = true;
                }
                else
                {
                    prev = temp;
                    temp = temp->next;
                }
            }
        }
        if (mpp[temp->val])
        {
            ListNode *alpha = temp;
            temp = temp->next;
            (prev) ? prev->next = temp : prev = NULL;
            alpha->next = NULL;
        }
        else
        {
            if (!flag)
            {
                start = temp;
                prev = start;
                temp=temp->next;
                flag = true;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        return start;
    }
};