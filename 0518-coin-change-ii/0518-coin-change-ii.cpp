class Solution {
public:
    int n;
    int dp[301][5001];
    vector<int>*arr;
    int rec(int level,int sleft){
        if(sleft==0){
            return 1;
        }
        if(level==n){
            if(sleft==0)return 1;
            return 0;
        }
        if(dp[level][sleft]!=-1)return dp[level][sleft];
        int ans = rec(level + 1, sleft); 
        if((*arr)[level] <= sleft)
            ans += rec(level, sleft - (*arr)[level]); 
        return dp[level][sleft]=ans;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        memset(dp,-1,sizeof(dp));
        arr=&coins;
        return rec(0,amount);
    }
};