class Solution {
public:
    vector<int>*arr;
    int n;
    int dp[5001][3];
    int rec(int level,int c){
        if(level==n)return 0;
        if(dp[level][c]!=-1)return dp[level][c];

        int ans =0;
        ans = (c==2)?max(ans,rec(level+1,0)):max(ans,rec(level+1,c));
        if(c==0){
            ans=max(ans,rec(level+1,c+1)-(*arr)[level]);
        }
        else if(c==1){
            ans=max(ans,rec(level+1,c+1)+(*arr)[level]);
        }

        return dp[level][c]=ans;
    }
    int maxProfit(vector<int>& prices) {
        this->n=prices.size();
        this->arr=&prices;
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
};