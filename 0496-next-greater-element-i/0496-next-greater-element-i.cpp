class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int>mpp;
        vector<int>nge(nums1.size());
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            if(st.empty()) mpp[nums2[i]]=-1;
            else{
                mpp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        for(int i= 0;i<nums1.size();i++){
            nge[i]=mpp[nums1[i]];
        }
        return nge;
    }
};