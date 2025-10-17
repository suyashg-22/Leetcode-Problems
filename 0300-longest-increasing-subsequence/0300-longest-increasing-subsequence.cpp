class Solution {
public:
    int dp[10001];
    vector<int>*arr;
    int n;
    int rec(int level){
        if(level<0)return 0;

        if(dp[level]!=-1)return dp[level];

        int maxi =1;
        for(int i=0;i<level;i++){
            if((*arr)[i]<(*arr)[level]){
                maxi=max(maxi,1+rec(i));
            }
        }
        return dp[level]=maxi;
    }
    int lengthOfLIS(vector<int>& nums) {
        n= nums.size();
        arr= &nums;
        memset(dp,-1,sizeof(dp));
        int ans =1;
        for(int i=0;i<n;i++){
            ans=max(ans,rec(i));
        }
        return ans;
    }
};