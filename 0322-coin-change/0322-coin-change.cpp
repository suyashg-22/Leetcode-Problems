class Solution {
public:
    int dp[13][10001];
    int rec(int level,int amnt,vector<int>&arr,int n){
        if(level==n){
            if(amnt==0)return 0;
            return 1e9;
        }
        if(dp[level][amnt]!=-1)return dp[level][amnt];
        int ans = rec(level+1,amnt,arr,n);
        if(arr[level]<=amnt){
            ans = min(ans,1+rec(level,amnt-arr[level],arr,n));
        }
        return dp[level][amnt]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp,-1,sizeof(dp));
        int ans= rec(0,amount,coins,n);
        if(ans>=1e9)return -1;
        return ans;
    }
};