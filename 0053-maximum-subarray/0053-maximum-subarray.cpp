class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n =nums.size();
        bool flag = true;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>=0)flag=false;
            maxi=max(maxi,nums[i]);
        }
        if(flag){
            return maxi;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum<0){
                sum=0;
            }
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};