class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first =lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        bool flag =true;
        if(first==n||nums[first] != target) flag =false;

        if(flag==false) return{-1,-1};
        int last =upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        return{first,last};
    }
};