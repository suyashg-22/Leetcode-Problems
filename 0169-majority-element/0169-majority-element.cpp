class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n =nums.size();
        int cnt=0;
        int el=-1;
        for(int i=0;i<n;i++){
            int x = nums[i];
            cnt+= (x==el)?1:-1;
            if(cnt<=0){
                cnt=1;
                el=x;
            }
        }
        return el;
    }
};