class Solution {
public:
    bool dp[201][20001];
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int tot = 0;
        for(auto it:nums)tot+=it;
        int temp =tot;
        for(int level=n;level>=0;level--){
            if(level<n){
                temp-=nums[level];
            }
            for(int sum1=temp;sum1>=0;sum1--){
                if(level==n){
                    if(2*sum1== tot)dp[level][sum1]=1;
                    else dp[level][sum1]=0;
                }
                else{
                    bool ans1= dp[level+1][sum1+nums[level]];
                    bool ans2= dp[level+1][sum1];
                    dp[level][sum1]=(ans1|ans2);
                }
            }
        }
        return dp[0][0];
    }
};