class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,int n){
        vis[node]=1;
        for(int i=0;i<n;i++){
            if(vis[i]==0 && adj[node][i]==1){
                dfs(i,adj,vis,n);
            }
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,isConnected,vis,n);
                cnt++;
            }
        }
        return cnt;
    }
};