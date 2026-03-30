class Solution {
public:
    int n;
    vector<int>*arr;
    int k;
    int dp[501];
    int rec(int level){
        if(level==n)return 0;
        if(dp[level]!=-1)return dp[level];

        int ans = 0;
        int maxi = INT_MIN;
        for(int j=level;j<level+k && j<n;j++){
            maxi=max(maxi,(*arr)[j]);
            ans=max(ans,(j-level+1)*maxi + rec(j+1));
        }
        return dp[level]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this->n=arr.size();
        this->k=k;
        this->arr=&arr;
        memset(dp,-1,sizeof(dp));

        return rec(0);
    }
};