class Solution {
public:
    int dp[1001][1001];
    int rec(int i,int j,string&s,int n){
        if(i>=n || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(s[i]==s[j]){
            ans=max(ans,1+rec(i+1,j-1,s,n));
        }
        else{
            ans=max(ans,rec(i+1,j,s,n));
            ans=max(ans,rec(i,j-1,s,n));
        }
        return dp[i][j]=ans;
    }
    int longestPalindromeSubseq(string s) {
       int n =s.size();
       memset(dp,-1,sizeof(dp));
        return rec(0,n-1,s,n);
    }
};