class Solution {
public:
    int n ;
    vector<int>*arr;
    int target;
    int dp[21][2001];
    int rec(int level,int sum){
        if(level==n){
            if(sum==target)return 1;
            else return 0;
        }
        int ind = sum>=0?sum:1000-sum;
        if(dp[level][ind]!=-1)return dp[level][ind];

        int ans=0;
        ans+=rec(level+1,sum+(*arr)[level]);
        ans+=rec(level+1,sum-(*arr)[level]);
        return dp[level][ind]=ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        this->n=nums.size();
        this->target=target;
        this->arr=&nums;
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
};