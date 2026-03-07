class Solution {
public:
    string s1 ;
    string s2;
    int n1;
    int n2;
    int dp[501][501];

    int rec(int i,int j){
        if(i==n1 || j==n2)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans =0;
        ans =max(ans,rec(i+1,j));
        ans=max(ans,rec(i,j+1));
        if(s1[i]==s2[j]){
            ans=max(ans,1+rec(i+1,j+1));
        }
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        this->s1=word1;
        this->s2=word2;
        this->n1 = word1.size();
        this->n2 = word2.size();

        memset(dp,-1,sizeof(dp));
        int ans = rec(0,0);
        return n1+n2-(2*ans);
    }
};