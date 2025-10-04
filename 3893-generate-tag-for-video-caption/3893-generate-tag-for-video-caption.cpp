class Solution {
public:
    string generateTag(string caption) {
        int n =caption.size();
        string s ="#";
        for(int i=0;i<n;i++){
            if(s.size()>=100){
                return s;
            }
            if(caption[i]==' ')continue;
            if(i!=0 && caption[i-1]==' ' && caption[i]!=' ' && s.size()>1){
                s+=toupper(caption[i]);
            }
            else s+=tolower(caption[i]);
        }
        return s;
    }
};