class Solution
{
public:
    queue<pair<int, int>> q;
    int m, n;
    vector<vector<int>> *arr;
    map<pair<int, int>, bool> vis;
    int cnt = 0;
    vector<pair<int, int>> padosi{{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
    int orange1 = 0;

    void bfs()
    {
        while (!q.empty())
        {
            int size = q.size();
            bool rotted_this_round = false; 
            for (int s = 0; s < size; s++)
            {
                auto p = q.front();
                q.pop();
                vis[p] = 1;
                int x = p.first;
                int y = p.second;

                for (int i = 0; i < padosi.size(); i++)
                {
                    pair<int, int> z = {x + padosi[i].first, y + padosi[i].second};
                    if (z.first >= 0 && z.first < m && z.second >= 0 && z.second < n)
                    {
                        if ((*arr)[z.first][z.second] == 1)
                        {
                            if (vis.find(z) == vis.end())
                            {
                                q.push(z);
                                vis[z] = 1;
                                (*arr)[z.first][z.second] = 2; 
                                orange1 -= 1;
                                rotted_this_round = true;
                            }
                        }
                    }
                }
            }
            if (rotted_this_round) cnt += 1; 
        }
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        arr = &grid;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] == 1)
                    orange1 += 1;
            }
        }

        bfs();

        if (orange1 != 0) return -1;
        return cnt; 
    }
};
