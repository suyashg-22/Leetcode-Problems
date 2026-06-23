class Solution {
public:
    int n;
    int dp[1001][1501];
    vector<int>arr;
    int minc;
    int rec(int level,int b,vector<vector<int>>&items){
        if(level==n) return b/minc;
        if(dp[level][b]!=-1)return dp[level][b];
        int ans=rec(level+1,b,items);
        if(b>=items[level][1]){
            ans=max(ans,arr[level]+rec(level+1,b-items[level][1],items));
        }
        return dp[level][b]=ans;
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        this->n=items.size();    
        memset(dp,-1,sizeof(dp));
        arr.resize(n);
        minc=INT_MAX;
        for(int i=0;i<n;i++){
            minc=min(minc,items[i][1]);
            int cnt=1;
            for(int j=0;j<n;j++){
                if(i!=j){
                    int f = items[i][0];
                    int ff = items[j][0];
                    if(ff%f==0)cnt++;
                }
            }
            arr[i]=cnt;
        }
        return rec(0,budget,items);
    }
};