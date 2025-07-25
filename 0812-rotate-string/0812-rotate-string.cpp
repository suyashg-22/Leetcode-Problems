class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        int m=goal.size();
        if(n!=m)return false;

        int i=0;
        string ans ="";
        int size =m;
        while(size>0){
            string temp = goal.substr(0,size);
            if(s.find(temp)==string::npos){
                size-=1;
            }
            else{
                i=s.find(temp);
                break;
            }
        }
        if(i==0 && size==m)return true;
        i=0;
        int j= size;
        while(i<n && j<m){
            if(s[i]!=goal[j])return false;
            i+=1;
            j+=1;
        }
        return true;
        
    }
};