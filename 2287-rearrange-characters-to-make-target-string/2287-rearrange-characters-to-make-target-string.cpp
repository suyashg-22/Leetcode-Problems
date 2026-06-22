class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int>mpp1;
        unordered_map<char,int>mpp2;
        for(auto c:target){
            mpp2[c]+=1;
        }
        for(auto c:s){
            if(mpp2.count(c))mpp1[c]+=1;
        }
        if(mpp1.size()!=mpp2.size())return 0;
        int cnt =0;
        bool flag = true;
        while(flag){
            for(auto& it:mpp1){
                char c = it.first;
                int v = it.second;

                int x = mpp2[c];
                if(v>=x){
                    mpp1[c]-=x;
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(flag)cnt+=1;
        }
        return cnt;
    }
};