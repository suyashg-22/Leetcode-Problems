class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int ans=0;
        if (nums.size() == 1 || nums[0] != nums[1]) {
            return nums[0];
        }
        
        for(int i=1;i<nums.size()-1;i++){

            if(nums[i] != nums[i-1] && nums[i] != nums[i+1]){
                return nums[i];
            }
        }
        
        return nums.back();
    }
};