class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int t =distanceThreshold;
        vector<vector<int>>dist(n,vector<int>(n,1e8));
        for(auto it:edges){
            int a=it[0];
            int b=it[1];
            int w=it[2];
            dist[a][b]=w;
            dist[b][a]=w;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j)dist[i][j]=0;
                    else if(dist[i][k]!=1e8 && dist[k][j]!=1e8){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        int mini=INT_MAX;
        int minicnt=INT_MAX;
        for(int i=n-1;i>=0;i--){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=t)cnt++;
            }
            if(cnt<minicnt){
                minicnt=cnt;
                mini=i;
            }
        }
        return mini;
    }
};