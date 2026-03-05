class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                cnt += (s[i]=='0')?0:1;
            }
            else{
                cnt += (s[i]=='1')?0:1;
            }
        }
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                cnt2 += (s[i]=='1')?0:1;
            }
            else cnt2 += (s[i]=='0')?0:1;
        }
        return min(cnt,cnt2);
    }
};