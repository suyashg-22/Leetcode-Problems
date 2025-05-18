class Solution {
public:
    long long fun(vector<int>&piles,int hrs){
        int n= piles.size();
        long long totalhrs=0;
        for(int i=0;i<n;i++){
            totalhrs += ceil((double)(piles[i])/(double)(hrs));
        }
        return totalhrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();
        int low =1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = INT_MAX;
        while(low<=high){
            int mid = low+(high-low)/2;
            long long totalhrs = fun(piles,mid);
            if(totalhrs<=h){
                ans = mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};