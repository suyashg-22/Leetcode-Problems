class Solution {
public:
    int d;
    vector<int>*arr;
    int dp[1001];
    int n;

    int rec(int level){
        if(level<0 || level>=n)return 0;
        if(dp[level]!=-1)return dp[level];

        int ans =0;
        int x = (*arr)[level];
        for(int i = level-1;i>=level-d;i--){
            if(i<0 )break;
            if((*arr)[i]>=x){
                break;
            }
            ans=max(ans,1+rec(i));
            ans=max(ans,rec(i));
        }
        for(int i=level+1;i<=level+d;i++){
            if(i>=n)break;
            if((*arr)[i]>=x){
                break;
            }
            ans=max(ans,1+rec(i));
            ans=max(ans,rec(i));
        }
        return dp[level]=ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        memset(dp,-1,sizeof(dp));
        this->arr=&arr;
        this->d=d;
        this->n=arr.size();
        int maxi =0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,rec(i));
        }
        return 1+maxi;
    }
};