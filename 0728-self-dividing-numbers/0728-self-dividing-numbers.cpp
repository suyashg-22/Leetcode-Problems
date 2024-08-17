class Solution {
public:


    bool isSDN(int x){
        string str = to_string(x);
        for(int i=0;i<str.length();i++){
            if(str[i]=='0') return false;
            if(x % (str[i] - '0') != 0) return false;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i=left;i<=right;i++){
            int cur = i ;
            if(isSDN(cur)){
                ans.push_back(cur);
            }
        }

        return ans;
    }
};