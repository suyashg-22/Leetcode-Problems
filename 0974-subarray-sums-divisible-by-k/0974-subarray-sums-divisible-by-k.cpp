class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>arr(2*k,0);
        int sum=0;
        int cnt =0;
        arr[0]=1;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            int ind = (((sum%k)+k)%k);
            cnt+= arr[ind];
            arr[ind]+=1;
        }
        return cnt;
    }
};