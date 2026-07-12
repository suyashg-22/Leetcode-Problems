class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n==0)return {};
        vector<pair<int,int>>brr(n);
        for(int i=0;i<n;i++){
            brr[i]={arr[i],i};
        }
        sort(brr.begin(),brr.end());
        vector<int>ans(n);
        int rnk=1;
        ans[brr[0].second]=rnk;
        for(int i=1;i<n;i++){
            int x = brr[i].first;
            int ind = brr[i].second;
            if(x==brr[i-1].first){
                ans[ind]=rnk;
            }
            else{
                rnk++;
                ans[ind]=rnk;
            }
        }
        return ans;
    }
};