class Solution {
public:
    int dp[101][2];
    int rec(int level,int c,vector<int>&arr,int n){
        if(level>=n)return 0;
        if(dp[level][c]!=-1)return dp[level][c];
        int ans= rec(level+1,c,arr,n);
        if(c==1 && level==n-1){
            return dp[level][c]=ans;
        }
        else{
            if(level==0)ans=max(ans,arr[level]+rec(level+2,1,arr,n));
            else ans= max(ans,arr[level]+rec(level+2,c,arr,n));
        }
        return dp[level][c]=ans;
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,nums,n);
    }
};