#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const long long mod = 1000000009;

#define asc(x) (x).begin(), (x).end()
#define desc(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define forl(i,a,b) for(ll i = (a); i < (b); i++)
#define fore(x,a) for(auto &x : a)
#define yes cout << "YES\n"
#define no cout << "NO\n"
class Solution {
public:
    int m, n;
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>>* arr;
    vector<pair<int, int>> padosi{{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
    vector<vector<int>> vis;

    void bfs() {
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.ff.ff;
            int y = p.ff.ss;
            int c = p.ss;

            for (int i = 0; i < 4; i++) {
                int nx = x + padosi[i].first;
                int ny = y + padosi[i].second;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (vis[nx][ny] == 0) {
                        vis[nx][ny] = 1;
                        (*arr)[nx][ny] = c + 1;
                        q.push({{nx, ny}, c + 1});
                    }
                }
            }
        }
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        m = isWater.size();
        n = isWater[0].size();
        arr = &isWater;
        vis.assign(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {      // ✅ water = source
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                    isWater[i][j] = 0;        // height of water
                } else {
                    isWater[i][j] = -1;       // land unvisited
                }
            }
        }

        bfs();
        return isWater;
    }
};
