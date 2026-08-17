class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,int n,vector<int>&vis){
        vis[node]=1;
        for(int i=0;i<n;i++){
            if(vis[i]==0 && adj[node][i]==1){
                dfs(i,adj,n,vis);
            }
        }
        return;
    }   
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n =isConnected.size();
        vector<int>vis(n,0);
        int ans =0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                dfs(i,isConnected,n,vis);
            }
        }
        return ans;
    }
};