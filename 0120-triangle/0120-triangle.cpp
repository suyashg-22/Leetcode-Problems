using ll = long long;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        ll r = triangle.size();
        ll dp[201][201];

        for(ll i=r-1;i>=0;i--){
            for(ll j=i;j>=0;j--){
                if(i==r-1){
                    dp[i][j]=triangle[i][j];
                }
                else{
                    ll ans =INT_MAX;
                    ans= min(ans,triangle[i][j]+dp[i+1][j]);
                    if(j+1<r)ans=min(ans,triangle[i][j]+dp[i+1][j+1]);
                    dp[i][j]=ans;
                }
            }
        }
        return dp[0][0];
    }
};