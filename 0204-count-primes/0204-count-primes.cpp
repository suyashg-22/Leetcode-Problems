class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<int>powervector(n,1);

        for(int i=2;i*i<n;i++){
            if(powervector[i]==1){
                for(int j= i*i;j<n;j+=i){
                    powervector[j]=0;
                }
            }
        }
        int cnt =0;
        for(int i =2;i<n;i++){
            if(powervector[i]==1) cnt+=1;
        }
        return cnt;
    }
};