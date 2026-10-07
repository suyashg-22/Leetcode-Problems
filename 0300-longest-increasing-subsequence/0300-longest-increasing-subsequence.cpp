class Solution {
public:
    int dp[2501];
    int rec(int level,vector<int>&arr,int n){

        if(dp[level]!=-1)return dp[level];
        int ans =1;
        for(int i=level-1;i>=0;i--){
            if(arr[i]<arr[level]){
                ans=max(ans,1+rec(i,arr,n));
            }
        }
        return dp[level]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n =nums.size();
        memset(dp,-1,sizeof(dp));
        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,rec(i,nums,n));
        }
        return maxi;
    }
};