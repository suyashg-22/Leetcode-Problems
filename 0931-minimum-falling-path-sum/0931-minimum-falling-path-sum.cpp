using ll = long long;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        ll r = matrix.size();
        ll dp[101][101];

        for (ll i = r - 1; i >= 0; i--) {
            for (ll j = r - 1; j >= 0; j--) {
                if (i == r - 1) {
                    dp[i][j] = matrix[i][j];
                } else {
                    ll ans = INT_MAX;
                    if (j - 1 >= 0)ans = min(ans, matrix[i][j] + dp[i + 1][j - 1]);
                    ans = min(ans, matrix[i][j] + dp[i + 1][j ]);
                    if (j + 1<r)ans = min(ans, matrix[i][j] + dp[i + 1][j + 1]);
                    dp[i][j]=ans;
                }
            }
        }
        ll mini =INT_MAX;
        for(ll i=0;i<r;i++)mini=min(mini,dp[0][i]);
        return mini;
    }
};