class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>ans(n);
        vector<int>freq(n+1,0);
        
        int cnt =0;
        for(int i=0;i<n;i++){
            freq[A[i]]+=1;
            freq[B[i]]+=1;
            if(A[i]==B[i]){
                if(freq[A[i]]==2)cnt+=1;
            }
            else{
                if(freq[A[i]]==2)cnt+=1;
                if(freq[B[i]]==2)cnt+=1;

            }
            ans[i]=cnt;
        }
        return ans;
    }
};