using ll = long long;
class Solution {
public:
    // vector<int>vis;
    vector<vector<int>>adj;
    ll dp[100001];
    ll dfs(int node,vector<int>&basetime){
        if(adj[node].size()==0){
            return dp[node]=basetime[node];
        }
        if(dp[node]!=-1)return dp[node];
        ll mini = LLONG_MAX;
        ll maxi = LLONG_MIN;
        for(auto nnode:adj[node]){
            ll ans = dfs(nnode,basetime);
            mini=min(mini,ans);
            maxi=max(maxi,ans);
        }
        ll ans = (2*maxi)-mini+basetime[node];
        return dp[node]=ans;
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        // vis.assign(n,0);
        memset(dp,-1,sizeof(dp));
        adj.resize(n);
        for(auto it:edges){
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
        }
        return dfs(0,baseTime);
    }
};