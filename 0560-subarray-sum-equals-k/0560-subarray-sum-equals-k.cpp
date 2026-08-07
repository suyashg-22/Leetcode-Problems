class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        int sum =0;
        int ans=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            int req=sum-k;
            if(mpp.count(req)){
                ans+= mpp[req];
            }
            if(sum==k)ans+=1;
            mpp[sum]+=1;
        }

        return ans;
    }
};