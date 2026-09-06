class Solution {
public:
    bool check(vector<int>&arr,int h,int mid){
        int n= arr.size();
        long long t=0;
        for(int i=0;i<n;i++){
            int temp = ceil(1.0*arr[i]/mid);
            if(t> INT_MAX-temp)return false;
            t+=temp;
        }
        return (t<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n =piles.size();
        int maxi=0;
        for(auto x:piles)maxi=max(maxi,x);
        if(n>h)return -1;
        int l=1;
        int r=maxi;
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(piles,h,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};