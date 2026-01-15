#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long mod = 1000000009;

#define asc(x) (x).begin(), (x).end()
#define desc(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define forl(i, a, b) for (ll i = (a); i < (b); i++)
#define fore(x, a) for (auto& x : a)
#define yes cout << "YES\n"
#define no cout << "NO\n"
class Solution {
public:
    int n, m;
    vector<vector<int>>* arr;
    vector<vector<bool>> vis;
    queue<pair<int, int>> q;
    int cnt =0;
    void bfs() {
        vector<pair<int, int>> padosi{{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};

        while (!q.empty()) {
            auto p = q.front();
            int x = p.ff;
            int y = p.ss;
            vis[x][y] = 1;
            q.pop();

            for (auto it : padosi) {
                int nx = x + it.ff;
                int ny = y + it.ss;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (!vis[nx][ny] && (*arr)[nx][ny] == 1) {
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                        cnt-=1;
                    }
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        n=grid[0].size();
        m=grid.size();
        arr=&grid;
        vis.assign(m,vector<bool>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
                else if(grid[i][j]==1){
                    cnt+=1;
                }
            }
        }
        bfs();
        return cnt;
    }
};