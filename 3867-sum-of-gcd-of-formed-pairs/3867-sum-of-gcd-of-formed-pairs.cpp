using ll = long long;
class Solution {
public:
    ll gcd(ll a, ll b){
        while(a>0 && b>0){
            if(a>=b){
                a = a%b;
            }
            else b= b%a;
        }
        if(a==0)return b;
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<ll>arr(n);
        ll ans =0;
        ll maxi =-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,(ll)nums[i]);
            arr[i]= gcd(maxi,(ll)nums[i]);
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n/2;i++){
            ans+= gcd(arr[i],arr[n-i-1]);
        }
        return ans;
    }
};