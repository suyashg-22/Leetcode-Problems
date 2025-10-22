class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n =nums.size();
        unordered_map<int,int>mpp;
        int maxi = 0;
        for(int i=0;i<n;i++){
            mpp[nums[i]]+=1;
            maxi=max(maxi,mpp[nums[i]]);
        }
        int ans =0;
        for(auto it:mpp){
            if(it.second==maxi)ans+=1;
        }
        return ans*maxi;
    }
};