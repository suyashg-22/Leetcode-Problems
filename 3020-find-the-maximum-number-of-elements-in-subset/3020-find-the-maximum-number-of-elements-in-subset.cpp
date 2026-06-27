using ll = long long;
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<ll,ll>mpp;
        set<ll>st;
        int cnt1=0;
        for(auto x:nums){
            if(x!=1){
                mpp[x]+=1;
                st.insert(x);
            }
            else cnt1+=1;
        }
        if(cnt1%2==0)cnt1-=1;
        ll maxi=max(1,cnt1);
        for(auto it=st.begin();it!=st.end();it++){
            ll cnt=0;
            ll x = *it;
            if(mpp[x]==1){
                cnt+=1;
                maxi=max(maxi,cnt);
            }
            else{
                ll xx = x*x;
                while(mpp.count(xx)){
                    st.erase(xx);
                    cnt+=2;
                    if(mpp[xx]==1){
                        break;
                    }
                    xx= xx*xx;
                }
                cnt+=1;
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
    }
};