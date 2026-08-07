class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        unordered_set<int>st;
        for(auto it:nums)st.insert(it);
        int ans=0;
        for(auto it :st){
            if(st.find(it-1)!=st.end())continue;
            int len=0;
            while(st.find(it)!=st.end()){
                len++;
                it++;
            }
            ans=max(ans,len);
        }
        return ans;
    }
};