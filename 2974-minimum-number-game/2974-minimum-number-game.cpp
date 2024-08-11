class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int>arr;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(i%2 == 1){
                arr.push_back(nums[i]);
                arr.push_back(nums[i-1]);
            }
        }

        return arr;
    }
};