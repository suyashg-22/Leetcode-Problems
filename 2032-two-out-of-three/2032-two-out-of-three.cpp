class Solution {
public:
    void fun(vector<int>&nums,vector<int>&arr){
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            arr[nums[i]]+=1;
        }
    }
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        sort(nums3.begin(),nums3.end());
        vector<int>arr(101,0);
        fun(nums1,arr);
        fun(nums2,arr);
        fun(nums3,arr);
        vector<int>ans;
        for(int i=0;i<101;i++){
            if(arr[i]>=2)ans.push_back(i);
        }
        return ans;
    }
};