using ll = long long ;
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        ll n= nums.size();
        vector<bool>arr(n,false);
        ll rem =0;
        for(ll i=0;i<n;i++){
            rem = (rem * 2 + nums[i]) % 5;
            arr[i] = (rem == 0);
        }
        return arr;
    }
};