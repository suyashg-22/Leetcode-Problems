class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi1=-1;
        int maxi2=-2;
        int n =nums.size();
        for(int i=0;i<n;i++){
            int x = nums[i];
            if(x>maxi1){
                maxi2=maxi1;
                maxi1=x;
            }
            else if(x>maxi2 || x==maxi1){
                maxi2=x;
            }
        }
        return (maxi1-1)*(maxi2-1);
    }
};