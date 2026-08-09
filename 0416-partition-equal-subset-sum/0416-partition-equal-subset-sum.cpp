class Solution {
public:
    int dp[201][20001];
    int sum=0;
    bool rec(int level,int s,vector<int>&arr,int n){
        if(level==n){
            return (s*2==sum);
        }
        if(dp[level][s]!=-1)return dp[level][s];
        bool ans=false;
        ans|= rec(level+1,s,arr,n);
        ans|= rec(level+1,s+arr[level],arr,n);
        return dp[level][s]=ans;
    }
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        for(auto it:nums)sum+=it;
        memset(dp,-1,sizeof(dp));
        return rec(0,0,nums,n);
    }
};