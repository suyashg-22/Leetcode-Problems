class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>nge(n);
        stack<int>st;
        int maxi = INT_MIN;
        int index =-1;
        for(int i= 0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                index =i;
            }
        }
        st.push(maxi);
        for(int i=index;i>=0;i--){
            while(!st.empty()&& st.top()<=nums[i]) st.pop();
            if(st.empty()) nge[i]=-1;
            else{
                nge[i]=st.top();
            }
            st.push(nums[i]);
        }       
        for(int i=n-1;i>index;i--){
            while(!st.empty()&& st.top()<=nums[i]) st.pop();
            if(st.empty()) nge[i]=-1;
            else{
                nge[i]=st.top();
            }
            st.push(nums[i]);
        }
        return nge;
    }
};