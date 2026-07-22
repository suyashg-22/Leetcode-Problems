class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string ss="";
        int n = s.size();
        vector<int>arr;
        ss+='1';
        arr.push_back(0);
        int cnt =1;
        int cnt1=0;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                ss+=s[i-1];
                arr.push_back(cnt);
                cnt=0;
            }
            cnt++;
        }      
        ss+=s[n-1];
        arr.push_back(cnt);
        ss+='1';
        arr.push_back(0);
        int m = ss.size();
        for(int i=0;i<m;i++){
            if(ss[i]=='1')cnt1+=arr[i];
        }
        int ans =cnt1;
        int i=0;
        while(i<m){
            char c = ss[i];
            if(c=='0')i++;
            else{
                if(i+4<m && ss[i+4]=='1'){
                    int temp1 = (ss[i+1]=='0')?arr[i+1]:0;
                    int temp2 = (ss[i+3]=='0')?arr[i+3]:0;
                    ans=max(ans,cnt1+temp1+temp2);
                    i+=2;
                }
                else i++;
            }
        }
        return ans;
    }
};