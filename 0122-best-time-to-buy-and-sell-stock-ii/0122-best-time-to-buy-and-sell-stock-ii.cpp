class Solution {
public:
    int dp[30001][2];
    int rec(int level,int c,vector<int>&arr,int n){
        if(level==n)return 0;
        if(dp[level][c]!=-1)return dp[level][c];
        int ans =0;
        if(c==0){
            ans=max(ans,rec(level+1,c,arr,n));
            ans=max(ans,rec(level+1,1,arr,n)-arr[level]);
        }
        else{
            ans=max(ans,rec(level+1,c,arr,n));
            ans=max(ans,rec(level+1,0,arr,n)+arr[level]);
        }
        return dp[level][c]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,prices,n);
    }
};