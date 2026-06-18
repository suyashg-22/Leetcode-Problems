class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n =nums.size();
        if(n==0)return 0;
        unordered_set<int>st;
        for(auto x:nums)st.insert(x);
        int maxi=1;
        for(auto x:st){
            if(st.find(x-1)==st.end()){
                int y = x;
                int len=1;
                while(st.find(y+1)!=st.end()){
                    y+=1;
                    len+=1;
                }
                maxi=max(maxi,len);
            }
        }
        return maxi;
    }
};