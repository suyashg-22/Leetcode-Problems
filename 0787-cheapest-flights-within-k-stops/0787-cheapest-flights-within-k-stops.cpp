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
    int src;
    int dst;
    int k;
    int n;
    vector<vector<pair<int, int>>> adj;
    vector<vector<int>>* arr;
    vector<int> dist;

    int dijk() {
        dist.assign(n + 1, INT_MAX);
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, src});
        dist[src] = 0;

        while (!q.empty()) {
            auto it = q.front();
            int cost = it.ff.ff;
            int s = it.ff.ss;
            int node = it.ss;
            q.pop();

            for (auto x : adj[node]) {
                int newnode = x.ff;
                int newcost = x.ss;
                if (newnode == dst) {
                    if (s > k && dist[newnode] == INT_MAX)return -1;
                    if (cost+newcost<dist[newnode] && s<=k){
                        dist[newnode]=cost+newcost;
                        q.push({{cost+newcost,s+1},newnode});
                    }
                } 
                else if (cost + newcost < dist[newnode]) {
                    dist[newnode] = cost + newcost;
                    q.push({{cost + newcost, s + 1}, newnode});
                }
            }
        }
        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        arr = &flights;
        this->n = n;
        this->src = src;
        this->dst = dst;
        this->k = k;
        this->adj.resize(n);

        for (auto it : flights) {
            adj[it[0]].pb({it[1], it[2]});
        }
        return dijk();
    }
};