#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int num = stoi(nums[i], nullptr, 2);
            if(num != ans) break;
            ans++;
        }

        string s = "";
        while(ans > 0) {
            s += (ans & 1) ? '1' : '0';
            ans >>= 1;
        }
        reverse(s.begin(), s.end());

        while(s.size() < n) s = '0' + s;

        return s;
    }
};
