class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n =nums.size();
        int a=0;
        int b=0;
        for(int i=0;i<n;i++){
            b^=(i+1);
            a^=nums[i];
        }
        return a^b;
    }
};