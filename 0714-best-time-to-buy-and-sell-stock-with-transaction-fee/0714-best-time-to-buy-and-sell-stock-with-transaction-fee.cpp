class Solution {
public:
    int fee;
    int n;
    vector<int>*arr;
    int dp[50001][2];
    int rec(int level,int c){
        if(level==n)return 0;
        if(dp[level][c]!=-1)return dp[level][c];

        int ans =0;
        ans = max(ans,rec(level+1,c));
        if(c==0){
            ans=max(ans,rec(level+1,1)-(*arr)[level]);
        }
        else{
            ans=max(ans,rec(level+1,0)+(*arr)[level]-fee);
        }
        return dp[level][c]=ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        this->arr=&prices;
        this->n=prices.size();
        this->fee=fee;
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
};