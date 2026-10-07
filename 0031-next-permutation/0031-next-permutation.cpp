class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n =nums.size();
        int ind = n-2;
        while(ind>=0 && nums[ind]>=nums[ind+1])ind--;
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1,nums.end());
        return;
    }
};