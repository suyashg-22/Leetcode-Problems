class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>mpp;
        for(int i=0;i<order.size();i++)mpp[order[i]]=i;

        for(int i=0;i<words.size()-1;i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int x=0;
            int y=0;
            int n = s1.size();
            int m = s2.size();
            while(x<n && y<m && s1[x]==s2[y]){
                x+=1;
                y+=1;
            }
            if(x<n && y<m){
                if(mpp[s1[x]]>=mpp[s2[y]])return false;
            }
            else if(x<n && x==m && y>=m)return false;
        }
        return true;
    }
};