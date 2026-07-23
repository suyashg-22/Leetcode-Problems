class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int nxt = (i+1>=n)?nums[0]:nums[i+1];
            int cur = nums[i];
            if(cur>nxt)cnt++;
        }
        if(cnt<=1)return true;
        return false;
    }
};