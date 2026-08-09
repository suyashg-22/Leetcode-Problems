class Solution {
public:
    int dp[501][501];
    int rec(int i,int j,string& s1,string &s2,int n,int m){
        if(i==n && j==m)return 0;
        if(i==n)return m-j;
        if(j==m)return n-i;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = 1e9;
        if(s1[i]==s2[j]){
            ans= rec(i+1,j+1,s1,s2,n,m);
        }
        else{
            ans= min(ans,1+rec(i,j+1,s1,s2,n,m));
            ans= min(ans,1+rec(i+1,j,s1,s2,n,m));
            ans= min(ans,1+rec(i+1,j+1,s1,s2,n,m));
        }
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,word1,word2,n,m);
    }
};