using ll = long long;
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        vector<vector<ll>>left(n+1);
        vector<vector<ll>>right(n+1);
        ll tot =0;
        ll ans = LONG_MAX;
        ll s = (1<<n);

        for(int i=0;i<2*n;i++){
            tot+=nums[i];
        }
        ll target=tot/2;
        for(int b = 0;b<s;b++){
            int cnt=0;
            ll lsum=0;
            ll rsum=0;
            for(int i=0;i<n;i++){
                int temp = (b & (1<<i));
                if(temp!=0){
                    lsum+=nums[i];
                    rsum+=nums[n+i];
                    cnt++;
                }
            }
            left[cnt].push_back(lsum);
            right[cnt].push_back(rsum);
        }
        for(int i=0;i<n+1;i++){
            sort(right[i].begin(),right[i].end());
        }
        for(int i=0;i<n+1;i++){
            for(auto x:left[i]){
                ll t = target-x;
                auto ind = lower_bound(right[n-i].begin(),right[n-i].end(),t)-right[n-i].begin();
                if(ind<right[n-i].size()){
                    ll sum1 = x+right[n-i][ind];
                    ll sum2 = tot-sum1;
                    ans=min(ans,abs(sum1-sum2));
                }
                if(ind>0){
                    ll sum1 = x+right[n-i][ind-1];
                    ll sum2 = tot-sum1;
                    ans=min(ans,abs(sum1-sum2));
                }
            }
        }
        return ans;
    }
};