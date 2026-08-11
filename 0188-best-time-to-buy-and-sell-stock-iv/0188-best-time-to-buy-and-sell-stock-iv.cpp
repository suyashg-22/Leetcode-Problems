class Solution {
public:
    int dp[1001][202];
    int rec(int level,int t,vector<int>&arr,int k,int n){
        if(level==n)return 0;
        if(t==2*k)return 0;
        if(dp[level][t]!=-1)return dp[level][t];
        int ans=0;
        ans=max(ans,rec(level+1,t,arr,k,n));
        if(t%2==0){
            ans=max(ans,-arr[level]+rec(level+1,t+1,arr,k,n));
        }
        else{
            ans=max(ans,arr[level]+rec(level+1,t+1,arr,k,n));
        }
        return dp[level][t]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n =prices.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,prices,k,n);
    }
};