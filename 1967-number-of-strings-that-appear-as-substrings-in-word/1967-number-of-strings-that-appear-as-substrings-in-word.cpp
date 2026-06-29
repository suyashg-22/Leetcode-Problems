class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        int m = word.size();
        int cnt=0;
        unordered_map<string,int>mpp;
        for(int i=0;i<n;i++){
            mpp[patterns[i]]+=1;
        }
            for(int j=0;j<m;j++){
                string ss="";
                for(int k=j;k<m;k++){
                    ss+=word[k];
                    if(mpp.count(ss)){
                        cnt+=mpp[ss];
                        mpp.erase(ss);
                    }
                }
            }
        return cnt;
    }
};