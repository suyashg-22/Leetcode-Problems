class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string a = "", x = "", b = "", y = "";
        bool flag1 = false, flag2 = false;
        
        // Parsing num1
        for(int i = 0; i < num1.length(); i++) {
            if(num1[i] == '+') {
                flag1 = true;  // After '+' is the imaginary part
                continue;
            }
            if(!flag1) {
                a += num1[i];  // Real part before '+'
            } else {
                if(num1[i] == 'i') {
                    break;  // Stop before 'i'
                }
                x += num1[i];  // Imaginary part after '+'
            }
        }
        
        // Parsing num2
        for(int i = 0; i < num2.length(); i++) {
            if(num2[i] == '+') {
                flag2 = true;  // After '+' is the imaginary part
                continue;
            }
            if(!flag2) {
                b += num2[i];  // Real part before '+'
            } else {
                if(num2[i] == 'i') {
                    break;  // Stop before 'i'
                }
                y += num2[i];  // Imaginary part after '+'
            }
        }
        
        // Convert parsed values to integers
        int A = stoi(a);
        int X = stoi(x);
        int B = stoi(b);
        int Y = stoi(y);
        
        // Perform the multiplication of complex numbers
        int realPart = (A * B) - (X * Y);
        int imagPart = (A * Y) + (B * X);
        
        // Construct the result as a string
        return to_string(realPart) + "+" + to_string(imagPart) + "i";
    }
};
