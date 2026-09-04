class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int>mpp;
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            int x = nums2[i];
            mpp[x]=i;
            while(!st.empty() && st.top()<=x){
                st.pop();
            }               
            if(st.empty())ans[i]=-1;
            else ans[i]=st.top();
            st.push(x);
        }
        int m= nums1.size();
        vector<int>ans2(m);
        for(int i=0;i<m;i++){
            ans2[i]=ans[mpp[nums1[i]]];
        }
        return ans2;
    }
};