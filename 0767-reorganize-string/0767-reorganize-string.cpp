class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mpp;
        for(auto c:s)mpp[c]+=1;
        priority_queue<pair<int,char>>pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(pq.size()>=2){
            auto it1 = pq.top();
            pq.pop();
            auto it2 = pq.top();
            pq.pop();
            ans+= it1.second;
            ans+= it2.second;
            if(it1.first>1)pq.push({it1.first-1,it1.second});
            if(it2.first>1)pq.push({it2.first-1,it2.second});
        }
        if(pq.empty())return ans;
        auto it = pq.top();
        if(it.first>1)return "";
        ans+=it.second;
        return ans;
    }
};