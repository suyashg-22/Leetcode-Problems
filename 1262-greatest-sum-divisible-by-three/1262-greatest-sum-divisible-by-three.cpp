int dp[40001][3];
class Solution {
public:
    int n;
    vector<int>* arr;

    int rec(int level, int sumr) {
        // base case FIRST
        if (level == n) {
            if (sumr == 0) return 0;
            return INT_MIN;
        }

        // now safe to check dp
        if (dp[level][sumr] != -1)
            return dp[level][sumr];

        int temp = (*arr)[level];

        // Option 1: skip
        int ans = rec(level + 1, sumr);

        // Option 2: take
        ans = max(ans, temp + rec(level + 1, (sumr + temp) % 3));

        return dp[level][sumr] = ans;
    }

    int maxSumDivThree(vector<int>& nums) {
        n = nums.size();
        arr = &nums;

        memset(dp,-1,sizeof(dp));
        return rec(0, 0);
    }
};
