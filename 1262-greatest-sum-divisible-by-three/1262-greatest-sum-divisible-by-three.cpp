int dp[40001][3];
class Solution {
public:
    int n;
    vector<int>* arr;
    const int NEG_INF = -1000000000;

    int rec(int level, int sumr) {
        // base case FIRST
        if (level == n) {
            if (sumr == 0) return 0;
            return NEG_INF;
        }

        // now safe to check dp
        if (dp[level][sumr] != INT_MIN)
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

        // initialize dp with INT_MIN
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < 3; j++)
                dp[i][j] = INT_MIN;

        return rec(0, 0);
    }
};
