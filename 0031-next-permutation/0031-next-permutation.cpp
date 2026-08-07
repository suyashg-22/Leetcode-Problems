class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind =-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int j=n-1;
        while(j>ind && nums[j]<=nums[ind])j--;
        swap(nums[ind],nums[j]);
        reverse(nums.begin()+ind+1,nums.end());
        return;
    }
};