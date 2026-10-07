using ll = long long;
class Solution {
public:
    bool check(int mid,vector<int>&arr,int m, int k){
        int n = arr.size();
        int cnt =0;
        int bcnt =0;
        for(int i=0;i<n;i++){
            if(arr[i]<=mid){
                cnt++;
                if(cnt==k){
                    bcnt++;
                    if(bcnt>=m)return true;
                    cnt=0;
                }
            }
            else{
                cnt=0;
            }
        }
        return (bcnt>=m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n =bloomDay.size();
        if(m>n/k)return -1;
        int l= INT_MAX;
        int h= INT_MIN;
        for(int i=0;i<n;i++){
            l=min(l,bloomDay[i]);
            h=max(h,bloomDay[i]);
        }
        int ans = h;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(check(mid,bloomDay,m,k)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};