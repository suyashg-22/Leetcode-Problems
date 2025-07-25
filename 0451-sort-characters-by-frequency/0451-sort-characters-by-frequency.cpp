class Solution {
public:
    string frequencySort(string s) {
        int n= s.size();
        sort(s.begin(),s.end());
        int cnt=1;
        priority_queue<pair<int,char>>pq;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])cnt+=1;
            else{
                pq.push({cnt,s[i-1]});
                cnt=1;
            }
        }
        pq.push({cnt,s[n-1]});
        string ans ="";
        while(!pq.empty()){
            string temp = string(pq.top().first,pq.top().second);
            ans+=temp;
            pq.pop();
        }
        return ans;
    }
};