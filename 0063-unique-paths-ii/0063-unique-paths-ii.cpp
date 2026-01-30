using ll =long long;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        ll r= obstacleGrid.size();
        ll c= obstacleGrid[0].size();
        ll dp[101][101];
        if(obstacleGrid[0][0]==1)return 0;

        for(ll i=r-1;i>=0;i--){
            for(ll j=c-1;j>=0;j--){
                if(i==r-1 && j==c-1){
                    if(obstacleGrid[i][j]==0)dp[i][j]=1;
                    else dp[i][j]=0;
                }
                else{
                    ll ans =0;
                    if(i+1<r && obstacleGrid[i+1][j]==0)ans+=dp[i+1][j];
                    if(j+1<c && obstacleGrid[i][j+1]==0)ans+=dp[i][j+1];
                    dp[i][j]=ans;
                }
            }
        }
        return dp[0][0];
    }
};