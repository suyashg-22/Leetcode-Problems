class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n =nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<=k;i++){
            if(i>=n)break;
            mpp[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            int x =nums[i];
            if(mpp[x]>1)return true;
            if(i+k+1<n){
                mpp[nums[i+k+1]]++;
            }
            if(i-k>=0){
                mpp[nums[i-k]]--;
                if(mpp[nums[i-k]]<=0)mpp.erase(nums[i-k]);
            }
        }
        return false;
    }
};