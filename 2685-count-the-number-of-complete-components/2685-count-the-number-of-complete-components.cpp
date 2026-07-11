class Solution {
public:
    pair<int,int> dfs(int node,vector<int>&vis,vector<vector<int>>&adj){
        vis[node]=1;
        int v=0;
        int cnt=0;
        for(auto nnode :adj[node]){
            if(vis[nnode]==0){
                auto p =dfs(nnode,vis,adj);
                v+=1+p.first;
                cnt+= adj[nnode].size()+p.second;
            }
        }
        return {v,cnt};
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it :edges){
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                auto p = dfs(i,vis,adj);
                int v = 1+p.first;
                int cnt = adj[i].size()+p.second;
                if(cnt == v*(v-1))ans++;
            }
        }
        return ans;
    }
};