class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr,brr;
        for(auto x:nums){
            if(x>=0)arr.push_back(x);
            else brr.push_back(x);
        }
        int a = arr.size();
        int b = brr.size();
        vector<int>ans(n);
        if(a>=b){
            for(int i=0;i<b;i++){
                ans[i*2]=arr[i];
                ans[i*2+1]=brr[i];
            }
            int ind = 2*b;
            for(int i=b;i<a;i++){
                ans[i]=arr[i];
                ind++;
            }
        }
        else{
            for(int i=0;i<a;i++){
                ans[i*2]=arr[i];
                ans[i*2+1]=brr[i];
            }
            int ind = 2*a;
            for(int i=a;i<b;i++){
                ans[ind]=brr[ind];
                ind++;
            }
        }
        return ans;
    }
};