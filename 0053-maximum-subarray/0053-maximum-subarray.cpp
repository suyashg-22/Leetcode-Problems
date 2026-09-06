class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n =nums.size();
        int maxi=INT_MIN;
        int sum=0;
        bool flag=false;
        for(auto x:nums){
            if(x>=0){
                flag=true;
                break;
            }
            maxi=max(maxi,x);
        }
        if(!flag)return maxi;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum<0)sum=0;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};