class Solution {
public:
    vector<vector<int>> adj;
    vector<int> level;
    int n;

    int bfs(int src) {
        queue<int> q;
        q.push(src);
        level[src] = 1;
        int mx = 1;

        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v : adj[u]) {
                if(!level[v]) {
                    level[v] = level[u] + 1;
                    mx = max(mx, level[v]);
                    q.push(v);
                } else if(abs(level[v] - level[u]) != 1) {
                    return -1;
                }
            }
        }
        return mx;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.assign(n + 1, {});

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(n + 1, 0);
        int ans = 0;

        for(int i = 1; i <= n; i++) {
            if(visited[i]) continue;

            // collect component
            vector<int> comp;
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            comp.push_back(i);

            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(int v : adj[u]) {
                    if(!visited[v]) {
                        visited[v] = 1;
                        q.push(v);
                        comp.push_back(v);
                    }
                }
            }

            int best = 0;
            for(int node : comp) {
                level.assign(n + 1, 0);
                int d = bfs(node);
                if(d == -1) return -1;
                best = max(best, d);
            }

            ans += best;
        }

        return ans;
    }
};
