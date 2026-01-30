class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int dp[201][201];
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                if(i==r-1 && j==c-1){
                    dp[i][j]=grid[i][j];
                }
                else{
                    int ans =INT_MAX;
                    if(j+1<c)ans=min(ans,grid[i][j]+dp[i][j+1]);
                    if(i+1<r)ans=min(ans,grid[i][j]+dp[i+1][j]);
                    dp[i][j]=ans;
                }
            }
        }
        return dp[0][0];
    }
};