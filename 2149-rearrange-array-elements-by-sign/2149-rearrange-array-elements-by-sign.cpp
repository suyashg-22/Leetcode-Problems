class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr,brr;
        for(auto x:nums){
            if(x>=0)arr.push_back(x);
            else brr.push_back(x);
        }
        vector<int>ans;
        int l=0;
        int r=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                ans.push_back(arr[l]);
                l++;
            }
            else{
                ans.push_back(brr[r]);
                r++;
            }
        }      
        return ans;
    }
};