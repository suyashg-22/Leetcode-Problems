class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n =nums.size();
        vector<int>arr(32,0);

        for(int i=0;i<n;i++){
            int temp =nums[i];
            for(int j=0;j<32;j++){
                int a = 1<<j;
                int res = temp & a;
                if(res!=0){
                    arr[j]+=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<32;i++){
            if(arr[i]%3!=0){
                int x = 1<<i;
                ans += x;
            }
        }
        return ans;
    }
};