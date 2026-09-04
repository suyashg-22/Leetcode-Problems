class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int>mpp;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            int x = nums2[i];
            mpp[x]=i;
            while(!st.empty() && st.top()<=x){
                st.pop();
            }               
            if(st.empty())mpp[x]=-1;
            else mpp[x]=st.top();
            st.push(x);
        }
        int m= nums1.size();
        vector<int>ans(m);
        for(int i=0;i<m;i++){
            ans[i]=mpp[nums1[i]];
        }
        return ans;
    }
};