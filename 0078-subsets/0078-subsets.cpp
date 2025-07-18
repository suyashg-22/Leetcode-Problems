class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n= nums.size();
        int size = (1<<n)-1;
        vector<vector<int>>ans;
        for(int num=0;num<=size;num++){
            vector<int>arr;
            for(int i=0;i<n;i++){
                if(((num)&(1<<i))){
                    arr.push_back(nums[i]);
                }
            }
            ans.push_back(arr);
        }
        return ans;
    }
};