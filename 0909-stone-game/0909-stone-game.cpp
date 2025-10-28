int dp[251][125001];
class Solution {
public:
    int n;
    int total=0;
    vector<int>*arr;
    bool rec(int level,int sum){
        if(level==n/2){
            if(sum>(total-sum))return true;
            else return false;
        }
        if(dp[level][sum]!=-1)return dp[level][sum];
        bool ans = 0;
        if(level+1<=(n/2)){
            if(rec(level+1,sum+(*arr)[level])==1)ans=1;
            if(rec(level+1,sum+(*arr)[n-level-1])==1)ans=1;
        }
        if(level+2<=(n/2)){
            if(rec(level+2,sum+(*arr)[level]+(*arr)[level+1])==1)ans=1;
        }
        return dp[level][sum]=ans;
    }
    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        arr=&piles;
        for(int i=0;i<n;i++)total+=piles[i];
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
};