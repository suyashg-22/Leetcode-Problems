const long long mod = 1000000007;
using ll = long long;

class Solution {
public:
    ll n;
    vector<vector<pair<ll, ll>>> adj;
    vector<ll> dist;
    vector<ll> ways;

    ll dijk() {
        ways.assign(n,0);
        dist.assign(n, LONG_MAX);
        dist[0] = 0;
        ways[0]=1;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
                       greater<pair<ll, ll>>>
            pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto it = pq.top();
            ll node = it.second;
            ll d = it.first;
            pq.pop();

            for (auto x : adj[node]) {
                ll newnode = x.first;
                ll newd = x.second;
                if(d+newd==dist[newnode]){
                    ways[newnode]=ways[newnode]%mod + ways[node]%mod;
                }
                else if (d + newd < dist[newnode]) {
                    ways[newnode]=ways[node]%mod;
                    dist[newnode] = d + newd;
                    pq.push({dist[newnode], newnode});
                    
                }
            }
        }
        return ways[n-1]%mod;
    }
    
    int countPaths(int n, vector<vector<int>>& roads) {
        this->n = n;
        adj.resize(n);
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        return dijk();
    }
};