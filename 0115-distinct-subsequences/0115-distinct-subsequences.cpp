using ll = long long;
const ll mod = 1e9+9;
class Solution {
public:
    string s;
    string t;
    int n1;
    int n2;
    ll dp[1001][1001];

    // int rec(int level,int c){
    //     if(c==n2)return 1;
    //     if(level==n1)return 0;
    //     if(dp[level][c]!=-1)return dp[level][c];

    //     int ans=rec(level+1,c);
    //     if(t[c]==s[level]){
    //         ans+= rec(level+1,c+1);
    //     }
    //     return dp[level][c]=ans;
    // }

    int numDistinct(string s, string t) {
        this->s=s;
        this->t=t;
        this->n1=s.size();
        this->n2=t.size();
        memset(dp,-1,sizeof(dp));

        for(int level=n1;level>=0;level--){
            for(int c=n2;c>=0;c--){
                if(c==n2){
                    dp[level][c]=1;
                }
                else if(level==n1){
                    dp[level][c]=0;
                }
                else{
                    ll ans = dp[level+1][c];
                    if(s[level]==t[c]){
                        ans= (ans+dp[level+1][c+1])%mod;
                    }
                    dp[level][c]=ans;
                }
            }
        }
        return dp[0][0];
    }
};