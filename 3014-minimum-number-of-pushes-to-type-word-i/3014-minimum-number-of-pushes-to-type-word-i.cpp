class Solution {
public:
    int minimumPushes(string word) {
        int s = word.size();
        int d = s/8;
        int r = s%8;
        int ans = 8*(d)*(d+1)/2;
        ans+= r*(d+1);
        return ans;
    }
};