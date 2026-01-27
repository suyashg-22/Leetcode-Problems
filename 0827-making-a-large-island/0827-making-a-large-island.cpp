class Solution {
public:
    int n;
    vector<vector<int>>* arr;
    vector<int> parent;
    vector<int> rnk;
    vector<int> dx{-1, 0, 1, 0};
    vector<int> dy{0, -1, 0, 1};
    unordered_map<int, int> mpp;

    int findparent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findparent(parent[node]);
    }
    void dsu(int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if ((*arr)[nx][ny] == 1) {
                    int node = x * n + y;
                    int adjnode = nx * n + ny;
                    int upa = findparent(node);
                    int upb = findparent(adjnode);
                    int ra = rnk[upa];
                    int rb = rnk[upb];
                    if (upa == upb)
                        continue;
                    if (ra < rb) {
                        parent[upa] = upb;
                    } else if (rb < ra) {
                        parent[upb] = upa;
                    } else {
                        parent[upa] = upb;
                        rnk[upb] += 1;
                    }
                }
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        this->n = grid.size();
        arr = &grid;
        parent.resize(n * n);
        for (int i = 0; i < n * n; i++) {
            parent[i] = i;
        }
        rnk.assign(n * n, 0);
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dsu(i, j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    mpp[findparent(i*n+j)] += 1;
                    maxi = max(maxi, mpp[findparent(i*n+j)]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int cnt = 1;
                    unordered_set<int> st;
                    for (int z = 0; z < 4; z++) {
                        int ni = i + dx[z];
                        int nj = j + dy[z];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            if (grid[ni][nj] == 1) {
                                if (st.find(parent[ni * n + nj]) == st.end()) {
                                    st.insert(parent[ni * n + nj]);
                                    cnt += mpp[parent[ni * n + nj]];
                                }
                            }
                        }
                    }
                    maxi = max(maxi, cnt);
                }
            }
        }
        return maxi;
    }
};