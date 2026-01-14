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
    int m, n;
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>>* arr;
    vector<pair<int, int>> padosi{{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
    vector<vector<int>>vis;

    void bfs() {
        while (!q.empty()) {
            int size = q.size();
            auto p = q.front();
            q.pop();
            int x = p.ff.ff;
            int y = p.ff.ss;
            int c = p.ss;
            vis[x][y]=1;

            for (int i = 0; i < padosi.size(); i++) {
                pair<pair<int, int>, int> z = {
                    {x + padosi[i].first, y + padosi[i].second}, c + 1};
                int nx = z.ff.ff;
                int ny = z.ff.ss;
                int nc = z.ss;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (vis[nx][ny]==0) {
                        q.push(z);
                        (*arr)[nx][ny] = nc;
                        vis[nx][ny]=1;
                    }
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        arr = &mat;
        vis.assign(m,vector<int>(n,0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j]=1;
                }
            }
        }

        bfs();
        return mat;
    }
};