class Solution {
public:
    int rec(int l,int r,string &s,int dp[][501]){
        if(l>r){
            return 0;
        }
        if(l==r)return 1;
        if(dp[l][r]!=-1)return dp[l][r];

        int ans =1;
        ans=max(ans,rec(l,r-1,s,dp));
        ans=max(ans,rec(l+1,r,s,dp));
        if(s[l]==s[r]){
            ans =max(ans,2+rec(l+1,r-1,s,dp));
        }
        return dp[l][r]=ans;
    }
    int minInsertions(string s) {
        int n;
        int dp[501][501];
        n=s.size();

        memset(dp,-1,sizeof(dp));
        return n-rec(0,n-1,s,dp);
    }
};