class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>>ans;
        vector<pair<string,string>>arr(n);

        for(int i=0;i<n;i++){
            string s = strs[i];
            string ss = s;
            sort(ss.begin(),ss.end());
            arr[i]={ss,s};
        }
        sort(arr.begin(),arr.end());
        vector<string>temp;
        temp.push_back(arr[0].second);
        for(int i=1;i<n;i++){
            string s = arr[i].first;
            string ss = arr[i].second;
            if(s==arr[i-1].first){
                temp.push_back(ss);
            }
            else{
                ans.push_back(temp);
                temp.clear();
                temp.push_back(ss);
            }
        }
        if(temp.size()>0){
            ans.push_back(temp);
        }
        return ans;
    }
};