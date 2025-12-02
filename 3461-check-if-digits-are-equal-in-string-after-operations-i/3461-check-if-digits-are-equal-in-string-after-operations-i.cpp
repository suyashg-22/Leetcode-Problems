class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        while (n > 2) {
            string temp = "";
            for (int i = 0; i < n - 1; i++) {
                int sum = ((s[i] - '0') + (s[i + 1] - '0'))%10;
                temp += to_string(sum);
            }
            s = temp;
            n -=1;
        }
        return s[0] == s[1];
    }
};
