// using ll = long long;
const int mod = 1e9+7;
class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int>arr(n,1);
        
        for(int kk=1;kk<=k;kk++){
            
            for(int i=1;i<n;i++){
                arr[i]=(arr[i-1]+arr[i])%mod;
            }
        }
        return arr[n-1];
    }

}; 