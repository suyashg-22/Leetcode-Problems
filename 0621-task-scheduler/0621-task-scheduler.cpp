class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(27,0);
        for(auto c:tasks){
            freq[c-'A']+=1;
        }
        priority_queue<int>pq;
        for(auto it:freq){
            if(it>0)pq.push(it);
        }
        int ans =0;
        while(!pq.empty()){
            int cycle = n+1;
            vector<int>temp;
            int cnt=0;
            int cc=0;
            while(cc<cycle && !pq.empty()){
                if(pq.top()>1){
                    temp.push_back(pq.top()-1);
                }
                pq.pop();
                cc+=1;
                cnt+=1;
            }
            for(auto tt:temp){
                pq.push(tt);
            }
            ans+= (pq.empty())?cnt:(n+1);
        }
        return ans;
    }
};