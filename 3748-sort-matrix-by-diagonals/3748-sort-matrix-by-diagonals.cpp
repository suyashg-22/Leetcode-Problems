class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n));

        for (int k = n - 1; k >= 1 - n; k--) {
            vector<int> temp;

            int start = max(0, -k);
            int end   = min(n, n - k);

            for (int i = start; i < end; i++) {
                int j = i + k;
                temp.push_back(grid[i][j]);
            }

            if (k > 0) sort(temp.begin(), temp.end());
            else sort(temp.rbegin(), temp.rend());

            int x = 0;
            for (int i = start; i < end; i++) {
                int j = i + k;
                ans[i][j] = temp[x++];
            }
        }

        return ans;
    }
};
