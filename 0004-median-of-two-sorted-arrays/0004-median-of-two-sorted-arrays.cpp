class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n =nums1.size();
        int m = nums2.size();
        int i=0;
        int j=0;
        vector<int>arr;
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }
            else{
                arr.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            arr.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            arr.push_back(nums2[j]);
            j++;
        }
        int x = arr.size();
        int mid = arr.size()/2;
        long double ans =0;
        if(x%2==0 ){
            if(mid!=0) ans =(arr[mid]+arr[mid-1])/2.0;
    
        }    
        else ans=arr[mid];
        return ans;
    }
};