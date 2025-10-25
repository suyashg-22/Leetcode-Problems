class Solution {
public:
    string S ;
    int n;
    int dp[501][501];
    int rec(int l,int r){
        if(l>r){
            return 0;
        }
        if(l==r)return 1;
        if(dp[l][r]!=-1)return dp[l][r];

        int ans =1;
        ans=max(ans,rec(l,r-1));
        ans=max(ans,rec(l+1,r));
        if(S[l]==S[r]){
            ans =max(ans,2+rec(l+1,r-1));
        }
        return dp[l][r]=ans;
    }
    int minInsertions(string s) {
        n=s.size();
        S=s;
        memset(dp,-1,sizeof(dp));
        return n-rec(0,n-1);
    }
};