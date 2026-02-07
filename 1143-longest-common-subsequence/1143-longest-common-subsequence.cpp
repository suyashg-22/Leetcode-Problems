class Solution {
public:
    string s1;
    string s2;
    int n1;
    int n2;
    int dp[1001][1001];

    // int rec(int i,int j){
    //     if(i==n1 || j==n2)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int ans=rec(i+1,j);
    //     ans=max(ans,rec(i,j+1));
    //     if(s1[i]==s2[j]){
    //         ans=max(ans,1+rec(i+1,j+1));
    //     }

    //     return dp[i][j]=ans;
    // }

    int longestCommonSubsequence(string text1, string text2) {
        this->n1 = text1.size();
        this->n2 = text2.size();
        this->s1 = text1;
        this->s2 = text2;
        memset(dp,-1,sizeof(dp));
        for(int i=n1;i>=0;i--){
            for(int j=n2;j>=0;j--){
                if(i==n1 || j==n2){
                    dp[i][j]=0;
                }
                else{
                    int ans = dp[i+1][j];
                    ans=max(ans,dp[i][j+1]);
                    if(text1[i]==text2[j]){
                        ans=max(ans,1+dp[i+1][j+1]);
                    }
                    dp[i][j]=ans;
                }
            }
        }
        return dp[0][0];
    }
};