class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
          
        for(int i=0;i<n;i++){
            unordered_map<int,int>mpp;
            unordered_map<int,int>freq;

            for(int j=i;j<n;j++){
                int cur=nums[j];
                if(mpp.count(cur)){
                    int cnt = mpp[cur];
                    freq[cnt]-=1;
                    if(freq[cnt]==0)freq.erase(cnt);
                    mpp[cur]=cnt+1;
                    freq[mpp[cur]]+=1;
                }
                else{
                    mpp[cur]+=1;
                    freq[1]+=1;
                }

                if(mpp.size()==1){
                    ans=max(ans,j-i+1);
                }
                if(freq.size()==2){
                    auto it=freq.begin();
                    int f1 = it->first;
                    it++;
                    int f2 = it->first;
                    if(f1*2==f2 || f2*2==f1)ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};