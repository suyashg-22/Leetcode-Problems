class Solution {
public:
    int dp[1001][1001];
    int rec(int i,int j,string &s,string&t,int n,int m){
        if(j==m)return 1;
        if(i==n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = rec(i+1,j,s,t,n,m);
        if(s[i]==t[j]){
            ans+= rec(i+1,j+1,s,t,n,m);
        }
        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,s,t,n,m);
    }
};