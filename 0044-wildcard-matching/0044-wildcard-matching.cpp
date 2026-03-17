class Solution {
public:
    int n1;
    int n2;
    string s,p;
    int dp[2001][2001];
    
    bool rec(int i,int j){
        if(i==n1 && j==n2)return 1;
        if(j==n2)return 0;
        if(i==n1 && p[j]!='*')return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        bool ans = 0;
        if(p[j]=='*'){
            if(i<n1)ans = rec(i+1,j);
            ans = (ans | rec(i,j+1));
        }
        else if(p[j]=='?'){
            ans = rec(i+1,j+1);
        }
        else{
            if(s[i]==p[j]){
                ans = rec(i+1,j+1);
            }
            else{
                ans = 0;
            }
        }
        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        this->s=s;
        this->p=p;
        this->n1=s.size();
        this->n2=p.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
};