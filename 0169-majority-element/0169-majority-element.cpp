class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n =nums.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int maxcnt=INT_MIN;
        int maxele=nums[0];
        for(auto it:mpp){
            if(maxcnt<it.second){
                maxcnt=it.second;
                maxele=it.first;
            }
        }
        return maxele;
    }
};