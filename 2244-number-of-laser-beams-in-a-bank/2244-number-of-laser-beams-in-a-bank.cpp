class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n =bank.size();
        int m =bank[0].size();
        long long ans =0;
        int prev =0;
        for(auto i:bank[0]){
            if(i=='1')prev+=1;
        }
        for(int i=1;i<n;i++){
            int cur =0;
            for(auto j:bank[i]){
                if(j=='1')cur+=1;
            }
            if(cur==0)continue;
            ans+=(prev*cur);
            prev=cur;
        }
        return ans;
    }
};