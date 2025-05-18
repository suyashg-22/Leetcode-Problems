class Solution {
public:
    bool fun(vector<int>&arr,int mid,int m,int k){
        int cnt =0;
        int cntb=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=mid){
                cnt+=1;
            }
            else{
                cntb += cnt/k;
                cnt = 0;
            }
        }
        cntb += cnt/k;
        if(cntb>=m) return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n= bloomDay.size();
        if(m>n/k) return -1;

        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans =high;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(fun(bloomDay,mid,m,k)==true){
                ans =mid;
                high=mid-1;
            }
            else{
                low =mid+1;
            }
        }
        return ans;
    }
};