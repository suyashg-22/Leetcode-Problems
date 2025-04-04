#include <iostream>
#include <climits>  // For INT_MAX and INT_MIN

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        
        while (x != 0) {
            int ld = x % 10;  // Get last digit
            x /= 10;  // Remove last digit
            
            // Overflow Check
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && ld > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && ld < -8)) return 0;

            rev = rev * 10 + ld;
        }

        return rev;
    }
};
