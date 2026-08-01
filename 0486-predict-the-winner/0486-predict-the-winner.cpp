class Solution {
public:
    int dp[21][21];
    int rec(int l,int r,vector<int>&arr){
        if(l==r)return arr[l];
        if(dp[l][r]!=-1)return dp[l][r];
        int maxi=arr[l]-rec(l+1,r,arr);
        maxi=max(maxi,arr[r]-rec(l,r-1,arr));
        return dp[l][r]=maxi;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,n-1,nums)>=0;
    }
};