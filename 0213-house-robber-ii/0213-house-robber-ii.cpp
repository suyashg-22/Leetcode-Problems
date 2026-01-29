class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int nxt = 0;
        int nxt2 = 0;

        for (int level = n - 1; level >= 0; level--) {
            int ans = 0;
            if (level == 0) {
                ans = nxt;
            } else {
                int ans1 = nxt;
                int ans2 = nums[level] + nxt2;
                ans = max(ans1, ans2);
            }
            nxt2 = nxt;
            nxt = ans;
        }
        int ans1 = nxt;
        nxt = 0;
        nxt2 = 0;
        for (int level = n - 1; level >= 0; level--) {
            int ans = 0;
            if (level == 0) {
                ans = nums[level] + nxt2;
            } else if (level == n - 1) {
                ans = nxt;
            } else {
                int ans1 = nxt;
                int ans2 = nums[level] + nxt2;
                ans = max(ans1, ans2);
            }
            nxt2 = nxt;
            nxt = ans;
        }
        int ans2 = nxt;
        return max(ans1, ans2);
    }
};