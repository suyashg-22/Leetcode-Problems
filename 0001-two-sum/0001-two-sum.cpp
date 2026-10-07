class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>arr(n);
        for(int i=0;i<n;i++)arr[i]=nums[i];
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        int x=INT_MIN;
        int y=INT_MIN;
        while(i<j){
            int sum = nums[i]+nums[j];
            if(sum==target){
                x=nums[i];
                y=nums[j];
                break;
            }
            else if(sum>target)j--;
            else i++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(arr[i]==x || arr[i]==y)ans.push_back(i);
        }
        return ans;
    }
};