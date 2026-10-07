class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n= nums.size();
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            int temp1 = (mid-1>=0)?nums[mid-1]:-1;
            int temp2 = (mid+1<n)?nums[mid+1]:-1;
            if(nums[mid]!=temp1 && nums[mid]!=temp2)return nums[mid];
            else if(nums[mid]==temp2){
                if(mid%2==0){
                    l=mid+1;
                }
                else h=mid-1;
            }
            else{
                if((mid-1)%2==0)l=mid+1;
                else h=mid-1;
            }
        }
        return -1;
    }
};