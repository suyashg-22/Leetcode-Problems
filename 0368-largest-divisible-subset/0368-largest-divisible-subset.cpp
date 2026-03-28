class Solution {
public:
    vector<int>*arr;
    int n;
    int dp[1001];
    vector<int>hash;

    int rec(int level){
        if(level<0)return 0;
        if(dp[level]!=-1)return dp[level];

        int ans =1;
        for(int l = 0;l<level;l++){
            if((*arr)[level]%(*arr)[l]==0){
                int ans2 = 1+rec(l);
                if(ans2>ans){
                    hash[level]=l;
                    ans=ans2;
                }
            }
        }
        return dp[level]=ans;
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        this->n=nums.size();
        this->arr=&nums;
        memset(dp,-1,sizeof(dp));
        hash.resize(n);
        for(int i=0;i<n;i++)hash[i]=i;
        sort(nums.begin(),nums.end());

        vector<int>ans;
        int maxi=1;
        int maxiind=0;
        for(int i=n-1;i>=0;i--){
            int ans2 = rec(i);
            if(ans2>maxi){
                maxi=ans2;
                maxiind=i;
            }
        }
        int i = maxiind;
        while(hash[i]!=i){
            ans.push_back(nums[i]);
            i=hash[i];
        }
        ans.push_back(nums[i]);
        return ans;
    }
};