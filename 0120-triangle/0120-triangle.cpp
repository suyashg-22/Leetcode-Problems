using ll = long long;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        ll r = triangle.size();

        vector<ll> last(r);
        for (ll i = 0; i < r; i++)
            last[i] = triangle[r - 1][i];

        for (ll i = r - 2; i >= 0; i--) {
            vector<ll> cur(r, INT_MAX);
            for (ll j = i; j >= 0; j--) {
                ll ans = INT_MAX;
                ans = min(ans, triangle[i][j] + last[j]);
                if (j + 1 < r)
                    ans = min(ans, triangle[i][j] + last[j + 1]);
                cur[j] = ans;
            }
            last = cur;
        }
        return last[0];
    }
};