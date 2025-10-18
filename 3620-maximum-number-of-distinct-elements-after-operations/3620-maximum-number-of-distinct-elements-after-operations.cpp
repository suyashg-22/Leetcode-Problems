class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        int ans =0;
        long long prev = LLONG_MIN;
        sort(nums.begin(),nums.end());
        for(auto x:nums){
            long long l = x-k;
            long long r = x+k;
            if(prev<l)prev=l;
            if(prev<=r){
                prev+=1;
                ans+=1;
            }
        }
        return ans;
    }
};