class Solution {
public:
    int rob(vector<int>& nums) {
        int n =nums.size();
        int dp[103];
        for(int level=n;level>=0;level--){
            if(level==n || level==n+1){
                dp[level]=0;
            }
            else{
                int ans = dp[level+1];
                ans=max(ans,nums[level]+dp[level+2]);
                dp[level]=ans;
            }
        }
        return dp[0];
    }
};