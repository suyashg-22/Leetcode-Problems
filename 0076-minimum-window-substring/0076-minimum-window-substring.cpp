class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>hash(256,0);
        int l=0;
        int r=0;
        int minlen = INT_MAX;
        int sindex=-1;
        for(int i=0;i<t.size();i++)hash[t[i]]+=1;
        int cnt =0;
        int m =t.size();
        int n =s.size();
        while(r<n){
            if(hash[s[r]]>0){cnt+=1;
            }
            hash[s[r]]-=1;
            while(cnt==m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sindex=l;
                }
                hash[s[l]]+=1;
                if(hash[s[l]]>0)cnt-=1;
                l+=1;
            }
            r+=1;
        }
        return sindex==-1?"":s.substr(sindex,minlen);
    }
};