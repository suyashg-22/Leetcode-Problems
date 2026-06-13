const long long mod = 26;
unordered_map<int, char> mp = {
    {1,'a'}, {2,'b'}, {3,'c'}, {4,'d'}, {5,'e'},
    {6,'f'}, {7,'g'}, {8,'h'}, {9,'i'}, {10,'j'},
    {11,'k'}, {12,'l'}, {13,'m'}, {14,'n'}, {15,'o'},
    {16,'p'}, {17,'q'}, {18,'r'}, {19,'s'}, {20,'t'},
    {21,'u'}, {22,'v'}, {23,'w'}, {24,'x'}, {25,'y'},
    {26,'z'}
};
class Solution {
public:

    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans ="";
        int n =words.size();
        for(int i=0;i<n;i++){
            string ss = words[i];
            int sum = 0;
            for(auto c: ss){
                sum= (sum+weights[c-'a'])%mod;
            }
            ans+= mp[26-sum];
        }
        return ans;
    }
};