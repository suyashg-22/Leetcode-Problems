class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n =nums.size();
        unordered_map<int,int>mpp;
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k)ans+=1;
            int req = sum-k;
            if(mpp.count(req)){
                ans+=mpp[req];
            }
            mpp[sum]++;
        }
        return ans;
    }
};