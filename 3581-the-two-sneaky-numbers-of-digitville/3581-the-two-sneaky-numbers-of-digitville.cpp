class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n= nums.size();
        int temp1 =-1;
        int temp2 =-1;
        for(int i=0;i<n;i++){
            mpp[nums[i]]+=1;
            if(mpp[nums[i]]==2 && temp1==-1)temp1=nums[i];
            else if(mpp[nums[i]]==2)temp2=nums[i];
        }
        return {temp1,temp2};
    }
};