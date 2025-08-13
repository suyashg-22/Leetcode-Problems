class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        auto &arr =cardPoints;
        int n = arr.size();
        int minisum =INT_MAX;
        int l =0;
        int r = n-k-1;
        int sum =0;
        int totalsum=0;
        for(int i=0;i<n;i++){
            if(i<n-k)sum+=arr[i];
            totalsum+=arr[i];
        }
        minisum=min(minisum,sum);
        while(r<n-1){
            r+=1;
            sum+=arr[r];
            sum-=arr[l];
            l+=1;
            minisum=min(minisum,sum);
        }
        return totalsum-minisum;
    }
};