class Solution {
public:
    int dp[102];
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        
        for(int level=n+1;level>=0;level--){
            if(level==n || level==n+1){
                dp[level]=0;
            }
            else{
                int ans =0;
                if(level==0){
                    ans=dp[level+1];
                }
                else{
                    ans= dp[level+1];
                    ans= max(ans,nums[level]+dp[level+2]);
                }
                dp[level]=ans;
            }
        }
        int ans1 = dp[0];

        memset(dp,-1,sizeof(dp));
        for(int level=n+1;level>=0;level--){
            if(level==n || level==n+1)dp[level]=0;
            else{
                int ans =0;
                if(level==0){
                    ans=nums[level]+dp[level+2];
                }
                else if(level==n-1){
                    ans=dp[level+1];
                }
                else{
                    ans=dp[level+1];
                    ans=max(ans,nums[level]+dp[level+2]);
                }
                dp[level]=ans;
            }
        }
        int ans2 =dp[0];
        return max(ans1,ans2);
    }
};