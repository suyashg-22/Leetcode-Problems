class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int carry = 0;
        int i = num1.size() - 1, j = num2.size() - 1;
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0'; // Convert char to int
            if (j >= 0) sum += num2[j--] - '0'; // Convert char to int
            
            carry = sum / 10;
            result += (sum % 10) + '0'; // Convert int to char and add to result
        }
        
        reverse(result.begin(), result.end()); // Since we added digits in reverse order
        return result;
    }
};
