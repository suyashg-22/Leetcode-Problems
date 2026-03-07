class Solution {
public:
    string s ;
    int n;
    int dp[1001][1001];

    int rec(int i, int j){
        if(i==n || j==-1){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans =0;
        ans = max(ans,rec(i+1,j));
        ans = max(ans,rec(i,j-1));
        if(s[i]==s[j]){
            ans = max(ans,1+rec(i+1,j-1));
        }
        return dp[i][j]=ans;
    }
    int longestPalindromeSubseq(string s) {
        this->s =s;
        this->n = s.size();
        memset(dp,-1,sizeof(dp));    
        return rec(0,n-1);
    }
};