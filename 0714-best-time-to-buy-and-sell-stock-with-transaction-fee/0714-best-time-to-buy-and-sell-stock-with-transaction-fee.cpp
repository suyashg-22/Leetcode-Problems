class Solution {
public:
    int dp[50001][2];
    int rec(int level,int t,vector<int>&arr,int n,int f){
        if(level>=n)return 0;
        if(dp[level][t]!=-1)return dp[level][t];
        int ans=0;
        ans=max(ans,rec(level+1,t,arr,n,f));
        if(t==0){
            ans=max(ans,-arr[level]+rec(level+1,1,arr,n,f));
        }
        else {
            ans=max(ans,-f+arr[level]+rec(level+1,0,arr,n,f));
        }
        return dp[level][t]=ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,prices,n,fee);
    }
};