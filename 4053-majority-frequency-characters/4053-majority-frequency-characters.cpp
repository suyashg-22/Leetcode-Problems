class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int>mpp;
        int n = s.size();
        int maxiii =-1;
        for(int i=0;i<n;i++){
            mpp[s[i]]+=1;
            maxiii=max(maxiii,mpp[s[i]]);
        }
        string ans ="";
        vector<int>arr(1+n,0);
        for(auto it:mpp){
            arr[it.second]+=1;
        }
        int maxi = INT_MIN;
        int maxiind = INT_MIN;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>=maxi){
                maxi=arr[i];
                maxiind =i;
            }
        }
        for(auto it:mpp){
            if(it.second==maxiind){
                ans+=it.first;
            }
        }
        return ans;
    }
};