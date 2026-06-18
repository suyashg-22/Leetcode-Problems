class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n =s1.size();
        int m =s2.size();
        unordered_map<char,int>mpp;
        for(auto c:s1)mpp[c]+=1;
        int i=0;
        int j=0;
        unordered_map<char,int>mpp2;
        while(i<m){
            char c =s2[i];
            if(!mpp.count(c)){
                mpp2.clear();
                i++;
                j=i;
            }
            else{
                mpp2[c]+=1;
                while(j<i && mpp2[c]>mpp[c]){
                    char cc = s2[j];
                    mpp2[cc]--;
                    if(mpp2[cc]<=0)mpp2.erase(cc);
                    j++;
                }
                if(mpp.size()==mpp2.size()){
                    bool flag = true;
                    for(auto it:mpp){
                        char c =it.first;
                        if(mpp[c]!=mpp2[c]){
                            flag=false;
                            break;
                        }
                    }
                    if(flag)return true;
                }
                i++;
            }
        }
        return false;
    }
};