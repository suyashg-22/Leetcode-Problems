using ll = long long int;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       ll n = nums.size();
        sort(nums.begin(),nums.end());
       ll l=0;
       ll r=0;
        ll res=0;
        ll total =0;
        while(r<n){
            total +=nums[r];
            if(nums[r]*(r-l+1)>total +k){
                total -= nums[l];
                l++;
            }
            res = max(res,(r-l+1));
            r++;
        }
        return res;
    }
};