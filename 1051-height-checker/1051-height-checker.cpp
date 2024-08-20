class Solution {
public:
    
    int heightChecker(vector<int>& heights) {
        vector<int>arr = heights;
        sort(heights.begin(),heights.end());
        
        int i=0;
        int j=0;
        int count =0;
        while(i<arr.size()&& j<heights.size()){
            if(arr[i] != heights[j]){
                count++;
            }
            i++;
            j++;
        }
        return count;
    }
};