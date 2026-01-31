class Solution {
public:
    int r,c;
    vector<int>dy{-1,0,1};
    int dp [71][71][71];
    vector<vector<int>>*arr;

    int rec(int i , int j1,int j2){
        if(i==r-1){
            if(j1==j2){
                return (*arr)[i][j1];
            }
            else return (*arr)[i][j1]+(*arr)[i][j2];
        }

        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int ans =0;
        for(auto it:dy){
            for(auto jt:dy){
                int nj1 = j1+it;
                int nj2 = j2+jt;
                if(nj1>=0 && nj1<c && nj2>=0 && nj2<c){
                    if(j1==j2){
                        ans=max(ans,(*arr)[i][j1]+rec(i+1,nj1,nj2));
                    }
                    else ans = max(ans,(*arr)[i][j1]+(*arr)[i][j2]+rec(i+1,nj1,nj2));
                }
            }
        }
        return dp[i][j1][j2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        this->r = grid.size();
        this->c = grid[0].size();
        this->arr=&grid;
        memset(dp,-1,sizeof(dp));
        return rec(0,0,c-1);
    }
};