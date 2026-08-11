class Solution {
public:
    int dp[2001][2001];
    bool rec(int i,int j,string &s,string&p,int n,int m){
        if(i==n && j==m)return true;
        if(j==m)return false;
        if(i==n && p[j]!='*')return false;

        if(dp[i][j]!=-1)return dp[i][j];
        bool ans =false;
        if(p[j]=='?'){
            ans= ans| rec(i+1,j+1,s,p,n,m);
        }
        else if(p[j]=='*'){
            if(i<n)ans=ans|rec(i+1,j,s,p,n,m);
            ans=ans|rec(i,j+1,s,p,n,m);
        }
        else if(s[i]==p[j])ans=ans|rec(i+1,j+1,s,p,n,m);

        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,s,p,n,m);
    }
};