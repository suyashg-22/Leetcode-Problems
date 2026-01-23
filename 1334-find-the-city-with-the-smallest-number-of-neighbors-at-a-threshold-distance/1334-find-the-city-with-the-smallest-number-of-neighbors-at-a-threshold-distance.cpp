class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int>(n, INT_MAX));
        for (auto x : edges) {
            adj[x[0]][x[1]] = x[2];
            adj[x[1]][x[0]] = x[2];
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j)
                        adj[i][j] = 0;
                    else {
                        if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX) {
                            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                        }
                    }
                }
            }
        }
        int th = distanceThreshold;
        int minicnt = INT_MAX;
        int ans = INT_MAX;
        for (int i = n-1; i>=0; i--) {
            int temp =0;
            for (int j = 0; j < n; j++) {
                if(adj[i][j]<=th)temp+=1;
            }

            if(temp<minicnt){
                minicnt = temp;
                ans = i;
            }
        }
        return ans;
    }
};