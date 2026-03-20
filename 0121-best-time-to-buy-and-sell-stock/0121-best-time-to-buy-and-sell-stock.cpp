class Solution {
public:
    vector<int>* arr;
    int dp[100001][3];
    int n;

    // int rec(int level,int c){
    //     if(c==2 || level==n) return 0;
    //     if(dp[level][c]!=-1)return dp[level][c];

    //     int ans =0;
    //     if(c==0){
    //         ans = max(ans,rec(level+1,c));
    //         ans = max(ans,rec(level+1,c+1)-(*arr)[level]);
    //     }
    //     else if(c==1){
    //         ans = max(ans,rec(level+1,c));
    //         ans = max(ans,(*arr)[level]+rec(level+1,c+1));
    //     }
    //     return dp[level][c]=ans;
    // }

    int maxProfit(vector<int>& prices) {
        this->arr= &prices;
        this->n = prices.size();
        memset(dp,-1,sizeof(dp));

        for(int level=n;level>=0;level--){
            for(int c=2;c>=0;c--){
                if(level==n || c==2){
                    dp[level][c]=0;
                }
                else {
                    int ans =0;
                    if(c==0){
                        ans=max(ans,dp[level+1][c]);
                        ans=max(ans,dp[level+1][c+1]-(*arr)[level]);
                    }
                    else if(c==1){
                        ans=max(ans,dp[level+1][c]);
                        ans=max(ans,dp[level+1][c+1]+(*arr)[level]);
                    }
                    dp[level][c]=ans;
                }
            }
        }
        return dp[0][0];    
    }
};