const long long mod = 1e9+7;
class Solution {
public:
    long long power(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
    }
    int maxi = 1;
    void dfs(int node,int d,vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        for(auto x : adj[node]){
            if(!vis[x]){
                int nd = (d+1)%mod;
                dfs(x,nd,adj,vis);
            }
        }
        maxi=max(maxi,d);
        
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>>adj(n+1);
        vector<int>vis(n+1);
        for(auto& it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(1,0,adj,vis);
        long long ans = power(2,maxi-1);
        return ans;
    }
};