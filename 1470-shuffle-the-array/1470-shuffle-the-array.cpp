class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int>arr;
        for(int i=0;i<nums.size() && n<nums.size();i++){
            arr.push_back(nums[i]);
            arr.push_back(nums[n]);
            n+=1;
        }
        return arr;
    }
};