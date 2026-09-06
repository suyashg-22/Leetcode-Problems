class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<string>st1;
        stack<int>st2;
        string ss="";
        int num=0;
        for(auto c:s){
            if(isdigit(c)){
                num*=10;
                num+= (c-'0');
            }
            else if(c=='['){
                st2.push(num);
                st1.push(ss);
                ss="";
                num=0;
            }
            else if(c==']'){
                string temp=ss;
                ss=st1.top();
                st1.pop();
                int t = st2.top();
                st2.pop();
                while(t--)ss+=temp;
            }
            else ss+=c;
        }
        return ss;
    }
};