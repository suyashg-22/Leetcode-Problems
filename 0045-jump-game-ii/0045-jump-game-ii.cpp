class Solution {
public:
    int jump(vector<int>& nums) {
        int n =nums.size();
        if(n==1){
            return 0;
        }
        int cnt =0;
        vector<int>arr(n);
        int maxi = nums[0];
        arr[0]=nums[0];
        for(int i=1;i<n;i++){
            int temp = i+nums[i];
            if(temp>maxi)maxi=temp;
            arr[i]=maxi;
        }
        int checkpoint = n-1;
        int i=n-2;
        while(i>=0){
            if(arr[i]<checkpoint){
                cnt+=1;
                checkpoint =i+1;
            }
            else{
                i-=1;
            }
        }
        return cnt+1;
    }
};