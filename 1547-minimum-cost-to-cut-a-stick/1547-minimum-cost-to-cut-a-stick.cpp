class Solution {
public:
    int dp[103][103];
    int rec(int i,int j,vector<int>&arr){
        if(j-i<=1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=1e9;
        for(int k=i+1;k<j;k++){
            ans=min(ans,arr[j]-arr[i]+rec(i,k,arr)+rec(k,j,arr));
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        return rec(0,m-1,cuts);
    }
};