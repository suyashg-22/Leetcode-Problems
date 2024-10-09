class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.length();
        int a = n/k;
        string ans = "";
        int sum=0;
        unordered_map<char,int>mp;
        mp['a']=0;
        mp['b']=1;
        mp['c']=2;
        mp['d']=3;
        mp['e']=4;
        mp['f']=5;
        mp['g']=6;
        mp['h']=7;
        mp['i']=8;
        mp['j']=9;
        mp['k']=10;
        mp['l']=11;
        mp['m']=12;
        mp['n']=13;
        mp['o']=14;
        mp['p']=15;
        mp['q']=16;
        mp['r']=17;
        mp['s']=18;
        mp['t']=19;
        mp['u']=20;
        mp['v']=21;
        mp['w']=22;
        mp['x']=23;
        mp['y']=24;
        mp['z']=25;
        int temp =0;
        for(int i=0;i<n;i++){
            sum+=mp[s[i]];
            temp=temp+1;
            if (temp==k){
                sum%=26;
                for(auto it: mp){
                    if(it.second == sum){
                        ans+=it.first;
                        break;
                    }
                }
                sum=0;
                temp=0;
            }
        }
        return ans;
    }
};