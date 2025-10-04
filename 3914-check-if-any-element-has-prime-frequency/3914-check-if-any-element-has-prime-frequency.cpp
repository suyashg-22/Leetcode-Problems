class Solution {
public:
    bool check(int x){
        if (x == 2 || x == 3 || x == 5 || x == 7 || x == 11 || x == 13 || x == 17 || x == 19 ||
    x == 23 || x == 29 || x == 31 || x == 37 || x == 41 || x == 43 || x == 47 ||
    x == 53 || x == 59 || x == 61 || x == 67 || x == 71 || x == 73 || x == 79 ||
    x == 83 || x == 89 || x == 97)return true;
    return false;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        int n =nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]+=1;
        }
        for(auto it:mpp){
            if(check(it.second)){
                return true;
            }
        }
        return false;
    }
};