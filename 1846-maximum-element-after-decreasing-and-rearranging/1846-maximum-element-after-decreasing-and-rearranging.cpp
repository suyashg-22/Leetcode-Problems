class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n =arr.size();
        int maxi=1;
        sort(arr.begin(),arr.end());
        int last =1;
        for(int i=1;i<n;i++){
            if(arr[i]>=last+1){
                maxi=max(maxi,last+1);
                last+=1;
            }
            else{
                maxi=max(maxi,last);
            }
        }
        return maxi;
    }
};