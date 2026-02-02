class Solution {
public:
    int n;
    vector<vector<int>>* grid;
    int dp[51][51][51];
    vector<vector<int>> d{{1,0,1,0},{0,1,0,1},{1,0,0,1},{0,1,1,0}};

    int rec(int i1,int j1,int j2){
        int i2 = i1 + j1 - j2;

        if(i1>=n || j1>=n || i2>=n || j2>=n) return -1e9;
        if((*grid)[i1][j1]==-1 || (*grid)[i2][j2]==-1) return -1e9;

        if(i1==n-1 && j1==n-1)
            return (*grid)[i1][j1];

        int &res = dp[i1][j1][j2];
        if(res!=-1) return res;

        int maxi = -1e9;
        for(auto &it:d){
            maxi = max(maxi, rec(i1+it[0], j1+it[1], j2+it[3]));
        }

        int cur = (*grid)[i1][j1];
        if(j1!=j2) cur += (*grid)[i2][j2];

        return res = cur + maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        this->grid = &grid;
        memset(dp, -1, sizeof(dp));

        int ans = rec(0,0,0);
        return max(0, ans);
    }
};
