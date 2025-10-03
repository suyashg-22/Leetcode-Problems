class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        bool f = true;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                f =false;
                break;
            }
        }
        return (f?0:1);
    }
};