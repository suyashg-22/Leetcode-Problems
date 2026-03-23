using ll = long long;
class Solution {
public:
    vector<int>*arr;
    ll n;
    ll dp[100001][5];
    ll rec(ll level,ll c){
        if(c==4)return 0;
        if(level==n){
            return 0;
        }
        if(dp[level][c]!=-1)return dp[level][c];
        ll ans =0;
        if(c%2==0){
            ans=max(ans,rec(level+1,c));
            ans=max(ans,rec(level+1,c+1)-(*arr)[level]);
        }
        else{
            ans=max(ans,rec(level+1,c));
            ans=max(ans,rec(level+1,c+1)+(*arr)[level]);
        }
        return dp[level][c]=ans;
    }
    ll maxProfit(vector<int>& prices) {
        this->arr=&prices;
        this->n = prices.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
};