class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ind = m+n-1;
        int l = m-1;
        int r = n-1;
        while(l>=0 && r>=0){
            if(nums1[l]>=nums2[r]){
                nums1[ind]=nums1[l];
                l--;
            }
            else{
                nums1[ind]=nums2[r];
                r--;
            }
            ind--;
        }
        while(l>=0){
            nums1[ind]=nums1[l];
            l--;
            ind--;
        }
        while(r>=0){
            nums1[ind]=nums2[r];
            r--;
            ind--;
        }
    }
};