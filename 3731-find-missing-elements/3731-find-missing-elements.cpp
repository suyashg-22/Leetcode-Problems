class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        int mini=101;
        int maxi=0;
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
            mpp[nums[i]]=1;
        }
        vector<int>ans;
        int num = mini+1;
        while(num<maxi){
            if(!mpp.count(num)){
                ans.push_back(num);
            }
            num++;
        }
        return ans;
    }
};