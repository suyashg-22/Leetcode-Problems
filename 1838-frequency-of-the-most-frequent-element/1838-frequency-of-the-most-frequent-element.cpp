class Solution {
public:

    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l =0;
        int r=0;
        long long sum = 0;
        int maxi =0;
        while(r<n){
            int x = nums[r];
            sum+=x;
            while(l<r && x>(sum+k)/(r-l+1)){
                sum-=nums[l];
                l+=1;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};