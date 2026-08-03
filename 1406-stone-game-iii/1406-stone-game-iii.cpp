class Solution {
public:
    int dp[50001];
    int rec(int level,vector<int>&arr,int n){
        if(level==n)return 0;
        if(dp[level]!=-1)return dp[level];
        int ans = arr[level]-rec(level+1,arr,n);
        if(level+1<n)ans=max(ans,arr[level]+arr[level+1]-rec(level+2,arr,n));
        if(level+2<n)ans=max(ans,arr[level]+arr[level+1]+arr[level+2]-rec(level+3,arr,n));
        return dp[level]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof(dp));
        int n = stoneValue.size();
        int ans = rec(0,stoneValue,n);
        if(ans==0)return "Tie";
        if(ans>0)return "Alice";
        return "Bob";
    }
};