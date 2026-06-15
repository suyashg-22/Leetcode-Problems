class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i=0;i<=n;i++){
            int cnt =0;
            int j=i;
            while(j>0){
                int temp= j&1;
                if(temp==1)cnt+=1;
                j>>=1;
            }
            ans[i]=cnt;
        }
        return ans;
    }
};