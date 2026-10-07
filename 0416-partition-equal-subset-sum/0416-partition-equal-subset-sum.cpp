class Solution {
public:
    int dp[201][20001];
    bool rec(int level,int sum,vector<int>&arr,int n,int tot){
        if(level>=n){
            if(2*sum==tot)return true;
            return false;
        }
        if(dp[level][sum]!=-1)return dp[level][sum];
        bool ans = rec(level+1,sum,arr,n,tot);
        ans |= rec(level+1,sum+arr[level],arr,n,tot);
        return dp[level][sum]=ans;
    }
    bool canPartition(vector<int>& nums) {
        int n =nums.size();
        int tot =0;
        for(auto x:nums)tot+=x;
        memset(dp,-1,sizeof(dp));
        return rec(0,0,nums,n,tot);
    }
};