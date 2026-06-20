class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int>diff(n,0);
        for(int i=0;i<n;i++){
            if(lights[i]>0){
                int x =lights[i];
                int l= max(0,i-x);
                int r= min(n-1,i+x);
                diff[l]+=1;
                if(r+1<n)diff[r+1]-=1;
            }
        }
        int len=0;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=diff[i];
            if(sum==0){
                len+=1;
            }
            else{
                if(len>0){
                    ans+= ceil(1.0*len/3);
                }
                len=0;
            }
        }
        if(len>0){
            ans+= ceil(1.0*len/3);
        }
        return ans;
    }
};