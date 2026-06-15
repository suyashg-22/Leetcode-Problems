class Solution {
public:
    int dp[1001][1001];
    int rec(int i,int j,string &s){
        if(i>j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans =0;
        if(s[i]==s[j]){
            ans = rec(i+1,j-1,s);
        }
        return dp[i][j]=ans;
    }
    int countSubstrings(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                ans+=rec(i,j,s);
            }
        }
        return ans;
    }
};