class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int sumr =0;
        for(int i=0;i<n;i++)sumr+=nums[i];
        int suml=0;
        int ind =-1;
        for(int i=0;i<n;i++){
            sumr-=nums[i];
            if(sumr==suml){
                ind=i;
                break;
            }
            suml+=nums[i];
        }
        return ind;
    }
};