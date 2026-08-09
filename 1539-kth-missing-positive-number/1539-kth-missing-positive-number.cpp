class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l=0;
        int h=n-1;
        int ans =-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            int missing = arr[mid]-1-mid;
            if(missing<k){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        if(ans==-1){
            return 0+k;
        }
        int x = arr[ans];
        int missing = arr[ans]-1-ans;
        return x+k-missing;
    }
};