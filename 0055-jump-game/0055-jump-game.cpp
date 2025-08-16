class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n =nums.size();
        if(n==1)return true;
        if(nums[0]==0){
            return false;
        }
        int maxi=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(nums[i]==0){
                if(maxi<=i)return false;
            }
            maxi=max(maxi,i+nums[i]);
        }
        return maxi>=n-1?true:false;
    }
};