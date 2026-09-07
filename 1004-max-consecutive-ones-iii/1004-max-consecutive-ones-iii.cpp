class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n =nums.size();
        int maxi=0;
        int kk=0;
        int i=0;
        int j=0;
        while(j<n){
            if(nums[j]==0)kk+=1;
            while(i<j && kk>k){
                if(nums[i]==0)kk-=1;
                i++;
            }
            if(kk<=k)maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};