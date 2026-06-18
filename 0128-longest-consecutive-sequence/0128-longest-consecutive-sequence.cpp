class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n =nums.size();
        if(n==0)return 0;
        set<int>st;
        for(auto x:nums)st.insert(x);
        int len=0;
        int maxi=0;
        int last=INT_MIN;
        for(auto sst:st){
            if(last==INT_MIN){
                last=sst;
                len=1;
                maxi=max(maxi,len);
            }
            else{
                if(sst==last+1){
                    len+=1;
                }
                else{
                    len=1;
                }
                maxi=max(maxi,len);
                last=sst;
            }
        }
        return maxi;
    }
};