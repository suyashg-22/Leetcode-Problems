using ll =long long ;
class Solution {
public:

    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0)return -1;
        vector<ll>arr(k,-1);
        ll n = 1;
        ll len =1;
        bool flag = true;
        while(true){
            ll temp =n%k;
            if(temp==0){
                break;
            }
            if(arr[temp]!=-1){
                flag = false;
                break;
            }
            arr[temp]=1;
            n= ((n*10)+1)%k;
            len+=1;
        }
        if(!flag)return -1;
        return len;
    }
};