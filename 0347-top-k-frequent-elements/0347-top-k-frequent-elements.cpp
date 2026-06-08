class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]+=1;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        int cnt =0;
        while(cnt<k && !pq.empty()){
            auto it = pq.top();
            ans.push_back(it.second);
            pq.pop();
            cnt+=1;
        }
        return ans;
    }
};