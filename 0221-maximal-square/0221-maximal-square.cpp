class Solution {
public:
    int dp[301][301];
    vector<vector<char>>* arr;
    int m, n;
    int maxi = 0;

    int rec(int r, int c) {
        if (r < 0 || c < 0) return 0;
        if ((*arr)[r][c] == '0') return 0;
        if (dp[r][c] != -1) return dp[r][c];

        int ans = 1 + min({rec(r-1, c), rec(r, c-1), rec(r-1, c-1)});
        maxi = max(maxi, ans);
        return dp[r][c] = ans;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        arr = &matrix;
        memset(dp, -1, sizeof(dp));
        m = matrix.size();
        n = matrix[0].size();
        maxi = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rec(i, j);
            }
        }

        return maxi * maxi;  // area of the largest square
    }
};
