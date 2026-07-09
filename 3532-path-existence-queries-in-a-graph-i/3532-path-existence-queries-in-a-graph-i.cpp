class Solution {
public:
    bool check(int base,int mid,vector<int>&nums,int md){
        return (nums[mid]-base<=md);
    }
    int bs(int l,int h,vector<int>&nums,int md){
        int ans = l;
        int base = nums[l];
        while(l<=h){
            int mid = l+(h-l)/2;
            if(check(base,mid,nums,md)){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
    
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>dp(n,-1);
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                dp[i]=n-1;
            }
            else{
                int far = bs(i,n-1,nums,maxDiff);
                if(far==i)dp[i]=i;
                else dp[i]=dp[far];
            }
        }
        int m = queries.size();
        vector<bool>ans(m);
        int i=0;
        for(auto it :queries){
            int a = min(it[0],it[1]);
            int b = max(it[1],it[0]);
            int far = dp[a];
            if(far>=b){
                ans[i]=true;
            }
            else ans[i]=false;
            i++;
        }        
        return ans;
    }
};