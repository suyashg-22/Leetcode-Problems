class Solution {
public:
    int maxArea(vector<int>& height) {
        int n =height.size();
        int i=0;
        int j=n-1;
        int ans = 0;
        while(i<j){
            int dist = abs(i-j);
            int water = height[i]<=height[j]?height[i]*dist:height[j]*dist;
            ans=max(ans,water);
            if(height[i]<=height[j])i+=1;
            else j-=1;
        }
        return ans;
    }
};