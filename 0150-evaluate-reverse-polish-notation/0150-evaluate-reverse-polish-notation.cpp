class Solution {
public:
    int f (int t1, int t2,string op){
        if(op=="+"){
            return t2 + t1;
        }
        else if (op=="-") return t2-t1;
        else if (op=="*") return t2*t1;
        return t2/t1;
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        int i =0;
        stack<int>st;
        while(i<n){
            if(tokens[i]=="+" ||tokens[i]=="-" ||tokens[i]=="*" ||tokens[i]=="/" ){
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.pop();
                string op = tokens[i];
                int res = f(t1,t2,op);
                st.push(res); 
            }
            else{
                st.push(stoi(tokens[i]));
            }
            i+=1;
        }
        return st.top();

    }
};