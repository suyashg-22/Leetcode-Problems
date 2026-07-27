using ll = long long;
class Solution {
public:
    int dp[501];
    int rec(int level,vector<int>&arr,int k,int n){
        if(level==n)return 0;
        if(dp[level]!=-1)return dp[level];
        ll ans=0;
        int limit = level+k;
        int maxi=-1;
        for(int i=level;i<limit;i++){
            if(i>=n)break;
            maxi=max(maxi,arr[i]);
            ans= max(ans, (ll)maxi*(i-level+1)+rec(i+1,arr,k,n));
        }
        return dp[level]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,arr,k,n);
    }
};