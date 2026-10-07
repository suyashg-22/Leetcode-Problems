class Solution {
public:
    int dp[1001][1001];
    int rec(int l,int r,string&s1,string&s2,int n,int m){
        if(l>=n || r>=m)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int ans =0;
        if(s1[l]==s2[r]){
            ans=max(ans,1+rec(l+1,r+1,s1,s2,n,m));
        }
        else{
            ans=max(ans,rec(l+1,r,s1,s2,n,m));
            ans=max(ans,rec(l,r+1,s1,s2,n,m));
        }
        return dp[l][r]=ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        int n = text1.size();
        int m = text2.size();
        return rec(0,0,text1,text2,n,m);
    }
};