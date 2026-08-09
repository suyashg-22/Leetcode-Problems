class Solution {
public:
    int dp[301][5001];
    int rec(int level,int amnt,vector<int>&arr,int n){
        if(level==n){
            if(amnt==0)return 1;
            return 0;
        }
        if(dp[level][amnt]!=-1)return dp[level][amnt];
        int ans = rec(level+1,amnt,arr,n);
        if(arr[level]<=amnt){
            ans+=rec(level,amnt-arr[level],arr,n);
        }
        return dp[level][amnt]=ans;
    }
    int change(int amount, vector<int>& coins) {
        int n =coins.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,amount,coins,n);
    }
};