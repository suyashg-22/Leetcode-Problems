class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int>vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int ans =0;
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            int w = it.first;
            int node = it.second;
            int a = points[node][0];
            int b = points[node][1];
            if(vis[node]==0){
                vis[node]=1;
                ans+=w;
                for(int i=0;i<n;i++){
                    if(vis[i]==0){
                        int c = points[i][0];
                        int d = points[i][1];
                        pq.push({abs(a-c)+abs(b-d),i});
                    }
                }
            }
        }
        return ans;
    }
};