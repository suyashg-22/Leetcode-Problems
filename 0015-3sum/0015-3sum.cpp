class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n =nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if((i-1>=0 && nums[i]==nums[i-1]))continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                long long sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && j-1>=0 && nums[j]==nums[j-1])j++;
                    while(k>j && k+1<n && nums[k]==nums[k+1])k--;
                }
                else if(sum>0){
                    k--;
                }
                else {
                    j++;
                }
            }
        }
        return ans;
    }
};