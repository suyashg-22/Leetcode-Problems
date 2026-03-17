class Solution {
public:
    string s1, s2;
    int n1, n2;
    int dp[501][501];

    int rec(int i,int j){
        if(i==n1 && j==n2)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        int ans = 1e8;
        if(i<n1 && j<n2 && s1[i]==s2[j]){
            ans = rec(i+1,j+1);
        }
        else{
            if(j<n2)ans=1+rec(i,j+1);
            if(i<n1)ans=min(ans,1+rec(i+1,j));
            if(j<n2)ans=min(ans,1+rec(i+1,j+1));
        }
        return dp[i][j]=ans;
    }

    int minDistance(string word1, string word2) {
        this->s1 = word1;
        this->s2 = word2;

        n1 = s1.size();
        n2 = s2.size();

        memset(dp, -1, sizeof(dp));

        return rec(0,0);
    }
};