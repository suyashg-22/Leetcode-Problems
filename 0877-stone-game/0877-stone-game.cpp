class Solution {
public:
    int dp[501][501];
    int rec(int l,int r,vector<int>&arr){
        if(l==r)return arr[l];
        if(dp[l][r]!=-1)return dp[l][r];
        int ans = arr[l]-rec(l+1,r,arr);
        ans = max(ans,arr[r]-rec(l,r-1,arr));
        return dp[l][r]=ans;
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int n = piles.size();
        return rec(0,n-1,piles)>0;
    }
};