class Solution {
public:
    string s;
    string t;
    int n1;
    int n2;
    int dp[1001][1001];

    int rec(int level,int c){
        if(c==n2)return 1;
        if(level==n1)return 0;
        if(dp[level][c]!=-1)return dp[level][c];

        int ans=rec(level+1,c);
        if(t[c]==s[level]){
            ans+= rec(level+1,c+1);
        }
        return dp[level][c]=ans;
    }

    int numDistinct(string s, string t) {
        this->s=s;
        this->t=t;
        this->n1=s.size();
        this->n2=t.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
};