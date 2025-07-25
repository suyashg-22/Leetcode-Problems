class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n= s.size();
        int i=0;
        map<char,char>mpp,mpp2;
        while(i<n){
            if(mpp2.find(t[i])!=mpp2.end() && (mpp2[t[i]]!=s[i])){
                return false;
            }
            if(mpp.find(s[i])!=mpp.end() &&(mpp[s[i]]!=t[i])){
                return false;
            }
            if(mpp.find(s[i])==mpp.end()){
                mpp[s[i]]=t[i];
            }
            if(mpp2.find(t[i])==mpp2.end()){
                mpp2[t[i]]=s[i];
            }
            i+=1;
        }
        return true;
    }
};