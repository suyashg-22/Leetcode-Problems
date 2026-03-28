class Solution {
public:
    int n;
    vector<int>*arr;
    int dp[2001];
    vector<int>hash;

    int rec(int level){
        if(level<0)return 0;
        if(dp[level]!=-1)return dp[level];

        int ans = 1;
        for(int l=0;l<level;l++){
            if((*arr)[l]<(*arr)[level]){
                int ans2=1+rec(l);
                if(ans2==ans){
                    hash[level]+=hash[l];
                }
                else if (ans2>ans){
                    ans=ans2;
                    hash[level]=hash[l];
                }

            }
        }
        return dp[level]=ans;
    }
    int findNumberOfLIS(vector<int>& nums) {
        this->n = nums.size();
        this->arr=&nums;
        memset(dp,-1,sizeof(dp));
        hash.assign(n+1,1);

        int maxi=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,rec(i));
        }
        for(int i=0;i<n;i++){
            if(dp[i]==maxi)cnt+=hash[i];
        }
        return cnt;
    }
};