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
// #define endl '\n'
class Solution {
public:
    int n;
    vector<vector<int>>* arr;
    vector<vector<int>> dist;

    void bfs() {

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        if ((*arr)[0][0] == 1)return;
        if (n == 1){
            dist[0][0]=1;    
            return ;
        }
        pq.push({1, {0, 0}});
        dist[0][0]=1;

        while (!pq.empty()) {
            vector<int> dx{0, -1, -1, -1, 0, 1, 1, 1};
            vector<int> dy{-1, -1, 0, 1, 1, 1, 0, -1};
            auto p = pq.top();
            pq.pop();
            int x = p.ss.ff;
            int y = p.ss.ss;
            int d = p.ff;

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < n && nx >= 0 && ny < n && ny >= 0) {
                    if ((*arr)[nx][ny] == 0) {
                        if(d+1<dist[nx][ny]){
                            dist[nx][ny]=d+1;
                            pq.push({d+1,{nx, ny}});
                        }
                    }
                }
            }
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        this->n = grid.size();
        arr = &grid;
        dist.assign(n, vector<int>(n, INT_MAX));

        bfs();
        if(dist[n-1][n-1]==INT_MAX)return -1;
        return dist[n-1][n-1];
    }
};