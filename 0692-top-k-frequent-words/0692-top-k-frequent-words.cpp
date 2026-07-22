class Solution {
public:
    static bool comp(const pair<int,string>&p1,const pair<int,string>&p2){
        if(p1.first!=p2.first){
            return p1.first>p2.first;
        }
        return p1.second<p2.second; 
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mpp;
        int n = words.size();
        for(int i=0;i<n;i++){
            string s = words[i];
            mpp[s]+=1;
        }
        vector<pair<int,string>>arr;
        for(auto it:mpp){
            arr.push_back({it.second,it.first});
        }
        sort(arr.begin(),arr.end(),comp);
        vector<string>ans;
        for(int i=0;i<k;i++){
            auto it = arr[i];
            ans.push_back(it.second);
        }
        return ans;
    }
};