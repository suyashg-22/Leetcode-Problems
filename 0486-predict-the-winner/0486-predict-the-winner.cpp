class Solution {
public:
    int dp[21][21];
    int rec(int l,int r,vector<int>&arr){
        if(l>r)return 0;
        if(l==r)return arr[l];
        if(dp[l][r]!=-1)return dp[l][r];
        int ans = -1e9;
        ans=max(ans,arr[l]-rec(l+1,r,arr));
        ans=max(ans,arr[r]-rec(l,r-1,arr));
        return dp[l][r]=ans;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n= nums.size();
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,n-1,nums);
        return (ans>=0);
    }
};