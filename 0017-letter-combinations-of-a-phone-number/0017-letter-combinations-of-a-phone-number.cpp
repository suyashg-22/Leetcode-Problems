class Solution {
public:
    unordered_map<char, string> mpp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };
    int n;
    vector<string>ans;

    void rec(int level,string &temp,string& s){
        if(level==n){
            ans.push_back(temp);
            return;
        }

        string ss = mpp[s[level]];
        int nn = ss.size();
        for(int i=0;i<nn;i++){
            temp+=ss[i];
            rec(level+1,temp,s);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        this->n=digits.size();
        string temp="";
        rec(0,temp,digits);
        return ans;
    }
};