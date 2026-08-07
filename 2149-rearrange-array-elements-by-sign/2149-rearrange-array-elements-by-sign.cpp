class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>arr,brr;
        for(auto x:nums){
            if(x>=0)arr.push_back(x);
            else brr.push_back(x);
        }
        vector<int>ans;
        int l=0;
        int r=0;
        int n=arr.size();
        int m=brr.size();
        while(l<n && r<m){
            ans.push_back(arr[l]);
            l++;
            ans.push_back(brr[r]);
            r++;
        }
        return ans;
    }
};