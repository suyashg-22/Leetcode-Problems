class Solution {
public:
    int dp[100001][5];
    int rec(int level,int t,vector<int>&arr,int n){
        if(level==n)return 0;
        if(t==4)return 0;
        if(dp[level][t]!=-1)return dp[level][t];
        int maxi =0;
        if(t%2==0){
            maxi=max(maxi,rec(level+1,t,arr,n));
            maxi=max(maxi,-arr[level]+rec(level+1,t+1,arr,n));
        }
        else{
            maxi=max(maxi,rec(level+1,t,arr,n));
            maxi=max(maxi,arr[level]+rec(level+1,t+1,arr,n));
        }
        return dp[level][t]=maxi;
    }
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,prices,n);
    }
};