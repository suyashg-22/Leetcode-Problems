class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int val =nums[i];
            if(val>=0 && val<nums.size()){
                ans.push_back(nums[val]);
            }
        }
        return ans;
    }
};