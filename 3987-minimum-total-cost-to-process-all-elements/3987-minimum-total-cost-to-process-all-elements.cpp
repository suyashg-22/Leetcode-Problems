const long long mod =1e9+7;
using ll = long long;
class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
        ll kk=k;
        ll avlbl=k;
        ll cost =1;
        ll ans =0;
        for(int i=0;i<n;i++){
            if(avlbl>=nums[i]){
                avlbl-=nums[i];
            }
            else{
                ll req = ceil(1.0 * (nums[i]-avlbl)/kk);
                ll temp1 = cost+req-1;
                ll a = temp1;
                ll b = temp1+1;
                ll c = cost-1;
                ll d = cost;
                (a%2==0)?a/=2:b/=2;
                (c%2==0)?c/=2:d/=2;
                ll sum1 = (a%mod)*(b%mod)%mod;
                ll sum2 = (c%mod)*(d%mod)%mod; 
                ans = (ans+(sum1-sum2)%mod)%mod;
                cost+=req;
                avlbl+= req*kk;
                avlbl-=nums[i];
            }
        }
        return ans;
    }
};