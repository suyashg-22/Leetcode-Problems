class Solution {
public:
    int dp[46];
    int climbStairs(int n) {

        for(int level=n;level>=0;level--){
            if(level==n){
                dp[level]=1;
            }
            else{
                int ans =0;
                ans+= dp[level+1];
                if(level+2<=n)ans+= dp[level+2];
                dp[level]=ans;
            }
        }
        return dp[0];
    }
};