class Solution {
public:
    int dp[13][10001];
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        for(int level=n;level>=0;level--){
            for(int val=amount;val>=0;val--){
                if(level==n){
                    if(val==amount)dp[level][val]=0;
                    else dp[level][val]=1e9;
                }
                else{
                    int ans =dp[level+1][val];
                    int t = (amount-val)/coins[level];
                    if(val<=amount-coins[level]){
                        ans=min(ans,1+dp[level][val+coins[level]]);
                    }
                    dp[level][val]=ans;
                }
            }
        }

        if(dp[0][0]>=1e9)return -1;
        return dp[0][0];
    }
};