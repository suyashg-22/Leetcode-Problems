class Solution {
public:

    int dp[105][105];
    int rec(int l,int r,vector<int>&cuts){

        if(l+1==r){
            return 0;
        }
        if(dp[l][r]!=-1)return dp[l][r];
        int cost = INT_MAX;
        for(int p = l+1;p<=r-1;p++){
            cost=min(cost,cuts[r]-cuts[l]+rec(l,p,cuts)+rec(p,r,cuts));
        }
        return dp[l][r]=cost;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int m = cuts.size();
        sort(cuts.begin(),cuts.end());
        memset(dp,-1,sizeof(dp));
        return rec(0,m-1,cuts);
    }
};