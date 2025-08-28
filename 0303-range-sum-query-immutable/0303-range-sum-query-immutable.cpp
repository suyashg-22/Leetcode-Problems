class NumArray {

public:
    vector<int>pref;
    NumArray(vector<int>& nums) {
        int n =nums.size();
        pref.resize(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        int ans =0;
        if(left>0){
            ans-=pref[left-1];
        }
        ans+=pref[right];
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */