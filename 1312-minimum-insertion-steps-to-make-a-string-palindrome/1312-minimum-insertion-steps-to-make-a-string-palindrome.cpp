class Solution {
public:
    string s;
    int n;
    int dp[501][501];
    int rec(int i,int j){
        if(i>j)return 0;
        if(i==j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans =0;
        ans =max(ans,rec(i+1,j));
        ans=max(ans,rec(i,j-1));
        if(s[i]==s[j]){
            ans=max(ans,2+rec(i+1,j-1));
        }
        return dp[i][j]=ans;
    }
    int minInsertions(string s) {
        this->s=s;
        this->n = s.size();
        memset(dp,-1,sizeof(dp));
        return n-rec(0,n-1);    
    }
};