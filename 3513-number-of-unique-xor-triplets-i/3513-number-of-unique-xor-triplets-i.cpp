class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<3)return n;

        int k = floor(1.0*log2(n))+1;
        int ans = 1<<(k);
        return ans;
    }
};