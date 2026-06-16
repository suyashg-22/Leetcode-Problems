class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")return "0";
        int n= num1.size();
        int m=num2.size();
        vector<int>arr(n+m,0);
        int space =0;
        for(int i=n-1;i>=0;i--){
            int c =0;
            int ind= n+m-1-space;
            for(int j=m-1;j>=0;j--){
                int sum = ((num1[i]-'0')*(num2[j]-'0'))+c+arr[ind];
                arr[ind]=sum%10;
                c=sum/10;
                ind-=1;
            }
            if(c>0){
                arr[ind]=c;
            }
            space+=1;
        }
        string s="";
        int i=0;
        while(i<n+m && arr[i]==0)i+=1;
        while(i<n+m){
            s+= (arr[i]+'0');
            i+=1;
        }
        return s;
    }
};