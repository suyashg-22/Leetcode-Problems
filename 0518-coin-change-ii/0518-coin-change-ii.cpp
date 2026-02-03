using ll = long long;
class Solution {
public:
    ll dp[301][5001];
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        for (int l = n; l >= 0; l--) {
            for (int sum = 0; sum <= amount; sum++) {

                if (l == n) {
                    if (sum == 0) {
                        dp[l][sum] = 1;
                    } else
                        dp[l][sum] = 0;
                }
                 else {

                    int ans = dp[l + 1][sum];
                    if (coins[l] <= sum) {
                        ans += dp[l][sum - coins[l]];
                    }
                    dp[l][sum] = ans;
                }
            }
        }
        return dp[0][amount];
    }
};