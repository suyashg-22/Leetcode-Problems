using ll = long long;
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        ll n = values.size();
        ll dp[51][51];
        // memset(dp,-1,sizeof(dp));
        for(ll len =3;len<=n;len++){
            for(ll l = 1;l+len-1<=n;l++){
                ll r = l+len-1;
                if(len==3){
                    dp[l][r]=values[l-1]*values[r-1]*values[l];
                }
                else{
                    ll ans =INT_MAX;
                    for(ll x = l+1;x<=r-1;x++){
                        if(x==l+1){
                            ans=min(ans,values[x-1]*values[r-1]*values[l-1] + dp[x][r]);
                        }
                        else if(x==r-1){
                            ans=min(ans,values[x-1]*values[l-1]*values[r-1] + dp[l][x]);
                        }
                        else{
                            ans=min(ans,dp[l][x]+dp[x][r]+ values[l-1]*values[r-1]*values[x-1]);
                        }
                    }
                    dp[l][r]=ans;
                }
            }
        }
        return dp[1][n];
    }
};