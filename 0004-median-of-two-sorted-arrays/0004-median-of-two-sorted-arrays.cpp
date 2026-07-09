class Solution {
public:
    int check(int mid,vector<int>&arr,vector<int>&brr){
        int n =arr.size();
        int m =brr.size();
        int size = (n+m)/2;
        int mid2 = size-mid;
        int l1 = (mid==0)?-1e9:arr[mid-1];
        int l2 = (mid2==0)?-1e9:brr[mid2-1];
        int r1 = (mid>=n)?1e9:arr[mid];
        int r2 = (mid2>=m)?1e9:brr[mid2];
        if(l1<=r2 && l2<=r1)return 1;
        else if(l1<=r2)return 2;
        return 0;
    }
    double bs(vector<int>&arr,vector<int>&brr){
        int n = arr.size();
        int m = brr.size();
        int size = (n+m)/2;
        int l=size-m;
        int h=size;
        double ans =-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            int mid2 = size-mid;

            if(check(mid,arr,brr)==1){
                int l1 = (mid==0)?-1e9:arr[mid-1];
                int l2 = (mid2==0)?-1e9:brr[mid2-1];
                int r1 = (mid>=n)?1e9:arr[mid];
                int r2 = (mid2>=m)?1e9:brr[mid2];
                if((n+m)%2==0){
                    ans= (max(l1,l2)+min(r1,r2))/2.0;
                }
                else ans = min(r1,r2);
                break;
            }
            else if(check(mid,arr,brr)==0){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n>=m)return bs(nums1,nums2);
        else return bs(nums2,nums1);
    }
};