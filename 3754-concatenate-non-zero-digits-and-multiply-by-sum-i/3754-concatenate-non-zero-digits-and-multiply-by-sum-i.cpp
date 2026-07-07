using ll = long long;
class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0)return 0;
        string s= "";
        string temp = to_string(n);
        ll size = temp.size();
        ll sum =0;
        for(ll i=0;i<size;i++){
            if(temp[i]!='0'){
                s+=temp[i];
                sum+= (temp[i]-'0');
            }
        }
        ll num = stoi(s);
        ll ans= num*sum;
        return ans;
    }
};