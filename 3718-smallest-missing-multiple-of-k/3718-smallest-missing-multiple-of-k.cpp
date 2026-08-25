class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        set<int>st;
        for(auto x:nums){
            if(x%k==0){
                st.insert(x);
            }
        }
        int temp =k;
        for(auto& it:st){
            if(it!=temp)return temp;
            temp+=k;
        }
        return temp;
    }
};