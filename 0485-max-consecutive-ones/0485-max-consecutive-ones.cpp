class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n= nums.size();
        int cnt =0;
        int maxi =INT_MIN;
        bool flag =false;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
                maxi=max(cnt,maxi);
                flag = true;
            }
            else{
                cnt=0;
            }
        }
        if(flag) return maxi;
        return 0;
    }
};