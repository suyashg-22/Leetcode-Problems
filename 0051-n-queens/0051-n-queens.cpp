class Solution {
public:
    int n;
    int dp[10];
    vector<vector<string>>ans;


    bool check(int level,int c){
        for(int i=0;i<level;i++){
            int qi = i;
            int qj = dp[i];
            if(c==qj || abs(qi-level)==abs(qj-c))return false;
        }
        return true;
    }

    void rec(int level){
        if(level==n){
            vector<string>temp;
            for(int i=0;i<n;i++){
                string s(n,'.');
                s[dp[i]]='Q';
                temp.push_back(s);
            }
            ans.push_back(temp);
            return;
        }

        for(int c = 0;c<n;c++){
            if(check(level,c)){
                dp[level]=c;
                rec(level+1);
                dp[level]=-1;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        this->n=n;
        memset(dp,-1,sizeof(dp));
        rec(0);
        return ans;
    }
};