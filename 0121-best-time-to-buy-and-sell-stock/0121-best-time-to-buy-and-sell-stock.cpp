class Solution {
public:
    vector<int>* arr;
    int dp[100001][2];
    int n;

    int rec(int level,int c){
        if(c==2 || level==n) return 0;
        if(dp[level][c]!=-1)return dp[level][c];

        int ans =0;
        if(c==0){
            ans = max(ans,rec(level+1,c));
            ans = max(ans,rec(level+1,c+1)-(*arr)[level]);
        }
        else if(c==1){
            ans = max(ans,rec(level+1,c));
            ans = max(ans,(*arr)[level]+rec(level+1,c+1));
        }
        return dp[level][c]=ans;
    }

    int maxProfit(vector<int>& prices) {
        this->arr= &prices;
        this->n = prices.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0);    
    }
};