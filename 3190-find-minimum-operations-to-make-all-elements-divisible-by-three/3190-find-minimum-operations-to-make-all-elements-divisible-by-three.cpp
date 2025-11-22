class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n= nums.size();
        int ans =0;
        for(auto i:nums){
            if(i%3!=0)ans+=1;
        }
        return ans;
    }
};