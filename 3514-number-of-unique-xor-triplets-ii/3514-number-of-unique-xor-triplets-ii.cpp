class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_map<int,int>mpp,mpp2;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int x1 =nums[i];
            if(!mpp.count(x1)){
                mpp[x1]=1;
            }
            for(int j=i;j<n;j++){
                int x2 = nums[j];
                int x = x1^x2;
                if(!mpp2.count(x)){
                    mpp2[x]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            int x1=nums[i];
            for(auto it:mpp2){
                int x2 = it.first;
                int x = x1^x2;
                if(!mpp.count(x)){
                    mpp[x]=1;
                }
            }
        }
        return mpp.size();
    }
};