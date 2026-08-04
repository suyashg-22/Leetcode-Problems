class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=1;i<n;i++){
            int cur = nums[i];
            int prev = nums[i-1];
            for(int j=prev+1;j<cur;j++)ans.push_back(j);
        }
        return ans;
    }
};