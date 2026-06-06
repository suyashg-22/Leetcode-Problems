class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        unordered_map<int,int>mpp1;
        unordered_map<int,int>mpp2;
        for(int i=0;i<n;i++){
            mpp2[nums[i]]+=1;
        }
        for(int i=0;i<n;i++){
            if(mpp2[nums[i]]==1)mpp2.erase(nums[i]);
            else mpp2[nums[i]]-=1;
            mpp1[nums[i]]+=1;
            ans[i]=mpp1.size()-mpp2.size();
        }
        return ans;
    }
};