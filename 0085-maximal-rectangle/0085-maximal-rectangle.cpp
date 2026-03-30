class Solution {
public:
    int f(vector<int> &heights) {
        int n =heights.size();
        stack<int>st;
        int maxi =0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int elindex = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty()?-1:st.top();
                maxi=max(maxi,heights[elindex]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int elindex = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty()?-1:st.top();
            maxi=max(maxi,heights[elindex]*(nse-pse-1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n =matrix.size();
        int m = matrix[0].size();
        vector<int>heights(m,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    heights[j]+=1;
                }
                else heights[j]=0;
            }
            maxi=max(maxi,f(heights));
        }        
        return maxi;
    }
};