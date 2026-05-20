class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>ans(n);
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[A[i]]+=1;
            int cnt =0;
            for(int j=0;j<=i;j++){
                if(mpp.count(B[j]))cnt+=1;
            }
            ans[i]=cnt;
        }
        return ans;
    }
};