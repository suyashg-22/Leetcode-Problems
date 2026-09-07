class Solution {
public:
    int dp[103][103];
    int rec(int l,int r,vector<int>&arr){
        if(l+1==r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int ans=1e9;
        for(int i=l+1;i<r;i++){
            ans=min(ans,arr[r]-arr[l]+rec(l,i,arr)+rec(i,r,arr));
        }
        return dp[l][r]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        memset(dp,-1,sizeof(dp));
        int m=cuts.size();
        return rec(0,m-1,cuts);
    }
};