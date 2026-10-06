class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int n = nums.size();
        for(auto x:nums)st.insert(x);
        int maxi=0;
        for(int i=0;i<n;i++){
            int x = nums[i];
            if(st.find(x+1)!=st.end())continue;
            else{
                int len=1;
                while(st.find(x-1)!=st.end()){
                    len++;
                    x--;
                    st.erase(x);
                }
                maxi=max(maxi,len);
            }
        }
        return maxi;
    }
};