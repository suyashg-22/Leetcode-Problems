class Solution {
public:
    int N;
    int dp[201][20001];
    int total=0;
    vector<int>*arr;
    bool rec(int level,int sum){
        if(level==N){
            if(sum==total-sum)return true;
            return false;
        }
        if(dp[level][sum]!=-1)return dp[level][sum];
        bool ans =0;
        if(rec(level+1,sum)==1)ans=1;
        if(rec(level+1,(*arr)[level]+sum)==1)ans=1;

        return dp[level][sum]=ans;
    }
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        arr = & nums;
        int n = nums.size();
        for(int i=0;i<n;i++)total+=nums[i];
        N=n;
        return rec(0,0);
    }
};