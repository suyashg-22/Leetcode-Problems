class Solution {
public:
    int m;
    vector<string>*arr;
    int dp[10][2][2];

    int rec(int level,bool tight,bool alreadytaken,string &s){
        if(level==m)return 1;
        if(dp[level][tight][alreadytaken]!=-1)return dp[level][tight][alreadytaken];

        int nn = (*arr).size();
        int ans=0;
        int limit = s[level]-'0';
        if(!alreadytaken)ans += rec(level+1,0,alreadytaken,s);
        for(int i=0;i<nn;i++){
            int temp = stoi((*arr)[i]);
            if(tight && temp>limit)break;

            if(tight && temp==limit){
                ans+= rec(level+1,1,1,s);
            }
            else ans+= rec(level+1,0,1,s);
        }
        return dp[level][tight][alreadytaken]=ans;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        this->m=s.size();
        memset(dp,-1,sizeof(dp));
        this->arr=&digits;

        return rec(0,1,0,s)-1;
    }
};