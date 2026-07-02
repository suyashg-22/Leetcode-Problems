class Solution {
public:
    bool dijk(vector<vector<int>>& arr, int health) {
        int n = arr.size();
        int m = arr[0].size();
        vector<int> dx{0, 1, 0, -1};
        vector<int> dy{-1, 0, 1, 0};

        priority_queue<pair<int,pair<int,int>>,
                       vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>>
            pq;
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0] = arr[0][0];
        pq.push({arr[0][0],{0, 0}});
        while (!pq.empty()) {
            auto it = pq.top();
            int i = it.second.first;
            int j = it.second.second;
            int d = it.first;
            pq.pop();
            for (int z = 0; z < 4; z++) {
                int ni = i + dx[z];
                int nj = j + dy[z];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    if (d + arr[ni][nj] < dis[ni][nj]) {
                        dis[ni][nj] = d+arr[ni][nj];
                        pq.push({d + arr[ni][nj],{ni, nj}});
                    }
                }
            }
        }
        return dis[n-1][m-1]<health;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        return dijk(grid, health);
    }
};