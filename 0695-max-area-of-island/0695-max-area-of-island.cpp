class Solution {
public:
vector<vector<int>> *arr;
    int n, m;
    vector<vector<bool>> vis;
    unordered_map<string, int> mpp;
    string ans = "";
    vector<int> dx{-1, 0, 1, 0};
    vector<int> dy{0, -1, 0, 1};

    void dfs_rec(int x, int y, char d)
    {
        // prereq-*arr,n,ans,vis
        vis[x][y] = 1;
        ans += d;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                if (!vis[nx][ny] && (*arr)[nx][ny] == 1)
                {
                    char c = 'z';
                    if (i == 0)
                        c = 't';
                    else if (i == 1)
                        c = 'l';
                    else if (i == 2)
                        c = 'd';
                    else
                        c = 'r';
                    dfs_rec(nx, ny, c);
                }
            }
        }
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        arr = &grid;
        vis.assign(m, vector<bool>(n, 0));
        int cnt = 0;
        int maxi =0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    cnt += 1;
                    dfs_rec(i, j, 'z');
                    maxi=max(maxi,(int)ans.size());
                    if (mpp.find(ans) != mpp.end())
                    {
                        cnt -= 1;
                    }
                    else
                    {
                        mpp[ans] = 1;
                    }
                    ans = "";
                }
            }
        }
        return maxi;
    }
};