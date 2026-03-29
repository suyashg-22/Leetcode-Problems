class Solution {
public:
    int n;
    vector<int>*arr;
    int dp[103][103];
    int rec(int l,int r){
        if(l+1==r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];

        int ans= 1e9;
        for(int k=l+1;k<r;k++){
            ans=min(ans,(*arr)[r]-(*arr)[l]+rec(l,k)+rec(k,r));
        }
        return dp[l][r]=ans;
    }


    int minCost(int n, vector<int>& cuts) {
        this->n=n;
        this->arr=&cuts;
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        memset(dp,-1,sizeof(dp));
        int size = cuts.size();
        return rec(0,size-1);    
    }
};