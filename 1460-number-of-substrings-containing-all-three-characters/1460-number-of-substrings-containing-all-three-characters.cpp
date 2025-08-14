class Solution {
public:
    long long f(string s,long long k){
        long long n =s.size();
        long long l =0;
        long long r =0;
        unordered_map<char,long long>mpp;
        long long cnt =0;
        while(r<n){
            mpp[s[r]]+=1;
            while(mpp.size()>k){
                mpp[s[l]]-=1;
                if(mpp[s[l]]==0)mpp.erase(s[l]);
                l+=1;
            }
            cnt+=r-l+1;
            r+=1;
        }
        return cnt;
    }
    int numberOfSubstrings(string s) {
        long long n =s.size();

        return n*(n+1)/2-f(s,2);
    }
};