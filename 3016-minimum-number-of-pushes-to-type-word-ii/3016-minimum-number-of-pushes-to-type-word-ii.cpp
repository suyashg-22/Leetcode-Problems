class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        int n =word.size();
        for(auto c:word){
            freq[c-'a']+=1;
        }
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<26;i++){
            pq.push({freq[i],'a'+i});
        }
        int cnt =0;
        int ans =0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            char c = it.second;
            int f = it.first;
            int v = cnt/8;
            ans+= (v+1)*f;
            cnt++;
        }
        return ans;
    }
};