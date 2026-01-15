class Solution {
public:
    vector<vector<int>>*arr, *brr;
    int n, m;
    vector<vector<bool>> vis;
    vector<int> dx{-1, 0, 1, 0};
    vector<int> dy{0, -1, 0, 1};
    bool flag = true;

    void dfs_rec(int x, int y) {
        // prereq-*arr,n,ans,vis
        vis[x][y] = 1;
        if ((*brr)[x][y] == 0) {
            flag = false;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (!vis[nx][ny] && (*arr)[nx][ny] == 1) {
                    if ((*brr)[nx][ny] == 0) {
                        flag = false;
                    }
                    dfs_rec(nx, ny);
                }
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        m = grid2.size();
        n = grid2[0].size();
        arr = &grid2;
        vis.assign(m, vector<bool>(n, 0));
        int cnt = 0;
        brr = &grid1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1 && !vis[i][j]) {
                    dfs_rec(i, j);
                    cnt += (!flag) ? 0 : 1;
                    flag = true;
                }
            }
        }
        return cnt;
    }
};