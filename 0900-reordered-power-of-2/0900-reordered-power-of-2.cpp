class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int temp = n;
        string s = to_string(temp);
        int size = s.size();
        
        sort(s.begin(),s.end());
        for(int i=0;i<31;i++){
            int req = (1<<i);
            string sreq = to_string(req);
            sort(sreq.begin(),sreq.end());
            if(sreq == s){
                return true;
            }
        }
        return false;
    }
};