class Solution {
public:

    bool checkPrimeFrequency(vector<int>& nums) {
        int n =nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]+=1;
        }
        for(auto it:mpp){
            if (it.second == 2 || it.second == 3 || it.second == 5 || it.second == 7 || it.second == 11 || it.second == 13 || it.second == 17 || it.second == 19 ||
    it.second == 23 || it.second == 29 || it.second == 31 || it.second == 37 || it.second == 41 || it.second == 43 || it.second == 47 ||
    it.second == 53 || it.second == 59 || it.second == 61 || it.second == 67 || it.second == 71 || it.second == 73 || it.second == 79 ||
    it.second == 83 || it.second == 89 || it.second == 97)return true;
        }
        return false;
    }
};