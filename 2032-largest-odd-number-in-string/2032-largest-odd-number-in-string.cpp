class Solution {
public:
    string largestOddNumber(string num) {
        int n= num.size();
        string ans ="";
        if((num[n-1]-'0')%2==1) return num;
        for(int i=n-1;i>0;i--){
            if((num[i]-'0')%2==0){
                if((num[i-1]-'0')%2==1){
                    ans=num.substr(0,i);
                    break;
                }
            }
           
        }
        if(ans==""){
            return "";
        }
        return ans;
    }
};