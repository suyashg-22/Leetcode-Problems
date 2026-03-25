class Solution {
public:
    int dp[1001][201];
    int n;
    vector<int>*arr;
    int k;

    int rec(int level,int c){
        if(c==2*k)return 0;
        if(level==n)return 0;
        if(dp[level][c]!=-1)return dp[level][c];

        int ans =0;
        ans = max(ans,rec(level+1,c));
        if(c%2==0){
            ans = max(ans,rec(level+1,c+1)-(*arr)[level]);
        }
        else{
            ans = max(ans,rec(level+1,c+1)+(*arr)[level]);
        }
        return dp[level][c]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        this->arr=&prices;
        this->n=prices.size();
        this->k=k;
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
};