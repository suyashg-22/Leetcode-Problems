class Solution {
public:
    int dp[21][2001];
    int target;
    int rec(int level,int sum,vector<int>&arr,int n){
        if(level==n){
            if(sum==target)return 1;
            return 0;
        }
        int ind = (sum<0)?1000-sum:sum;
        if(dp[level][ind]!=-1)return dp[level][ind];
        int ans = rec(level+1,sum-arr[level],arr,n);
        ans+= rec(level+1,sum+arr[level],arr,n);
        return dp[level][ind]=ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        this->target = target;
        int n =nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,nums,n);
    }
};