class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n =cardPoints.size();
        int lsum=0;
        for(int i=0;i<k;i++)lsum+=cardPoints[i];
        int maxi=lsum;
        int rsum=lsum;
        int l=k-1;
        for(int i=n-1;i>=n-k;i--){
            rsum-=cardPoints[l];
            l--;
            rsum+=cardPoints[i];
            maxi=max(maxi,rsum);
        }
        return maxi;
    }
};