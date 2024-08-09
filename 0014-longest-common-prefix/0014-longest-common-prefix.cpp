class Solution {
public:
    string longpref(vector<string>& strs,string& str1,string& str2,int i){
        string out="";
        if(i>=strs.size()){
            return str1;
        }
        int n1 = str1.size();
        int n2 = str2.size();
        int n = min(n1,n2);
        for(int j=0;j<n;j++){
            if(str1[j]==str2[j]){
                out+=str1[j];
            }
            
        }
        return longpref(strs,out,strs[i+1],i+1);
    }

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1){
            return strs[0];
        }
        return longpref(strs,strs[0],strs[1],0);
    }
};