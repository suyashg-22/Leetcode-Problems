class Solution {
public:
    int n;
    int cnt =0;
    vector<vector<int>>*arr;
    vector<int>vis;

    void dfs(int node){
        vis[node]=1;
        for(int i=0;i<n;i++){
            if((*arr)[node][i]==1){
                if(vis[i]==0){
                    dfs(i);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        arr=&isConnected;
        vis.assign(n,0);

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt+=1;
                dfs(i);
            }
        }
        return cnt;
    }
};