class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        for(int i=0;i<=k;i++){
            if(i>=n)break;
            mpp[nums[i]]+=1;
        }
        for(int i=0;i<n;i++){
            int x =nums[i];
            if(mpp[x]>=2)return true;
            if(i-k>=0){
                mpp[nums[i-k]]-=1;
                if(mpp[nums[i-k]]<=0)mpp.erase(nums[i-k]);
            }
            if(i+k+1<n){
                mpp[nums[i+k+1]]++;
            }
        }
        return false;
    }
};