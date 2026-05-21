class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        unordered_map<int,int>mpp;

        for(int i=0;i<n1;i++){
            string s = to_string(arr1[i]);
            int temp = 0;
            for(int j=0;j<s.size();j++){
                int x = s[j]-'0';
                temp+=x;
                mpp[temp]+=1;
                temp*=10;
            }
        }
        int ans =0;
        for(int i=0;i<n2;i++){
            string s = to_string(arr2[i]);
            int temp = arr2[i];
            for(int j=s.size()-1;j>=0;j--){
                if(mpp.count(temp)){
                    ans=max(ans,temp);
                    break;
                }
                temp/=10;
            }
        }

        if(ans==0)return 0;
        int len = to_string(ans).size();
        return len;
    }
};