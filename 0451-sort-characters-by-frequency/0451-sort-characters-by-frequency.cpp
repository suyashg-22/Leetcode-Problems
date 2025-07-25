class Solution {
public:
    string frequencySort(string s) {
        int n= s.size();
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]+=1;
        }
        string ans="";
        priority_queue<pair<int,char>>pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            string temp = string(pq.top().first,pq.top().second);
            ans+=temp;
            pq.pop();
        }
        return ans;
    }
};