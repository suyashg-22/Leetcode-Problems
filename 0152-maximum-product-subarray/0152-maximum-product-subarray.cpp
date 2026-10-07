class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int p=1;
        int s=1;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            p*=nums[i];
            s*=nums[n-i-1];
            maxi=max({maxi,p,s});
            if(p==0)p=1;
            if(s==0)s=1;
        }
        return maxi;
    }
};