class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        auto arr = reservedSeats;
        sort(arr.begin(),arr.end());
        int m = arr.size();
        int ans =0;
        bool f1=true;
        bool f2=true;
        bool f3=true;
        int temp=n;
        unordered_map<int,int>mpp;
        for(int i=0;i<m;i++){
            if(!mpp.count(arr[i][0])){
                temp-=1;
                mpp[arr[i][0]]=1;
            }
            if(i>0 && arr[i][0]!=arr[i-1][0]){
                if(!f1 && !f2 && !f3)ans+=0;
                else if((!f1 && !f2)||(!f1 && !f3) || (!f2 && !f3)||(!f1)||(!f2)||(!f3))ans+=1;
                else if((f1 && f2 && f3))ans+=2;
                f1=true;
                f2=true;
                f3=true;
            }

                int x = arr[i][1];
                if(x==2 || x==3)f1=false;
                else if(x==9 || x==8)f3=false;
                else if(x==4 || x==5){
                    f1=false;
                    f2=false;
                }
                else if(x==6 || x==7){
                    f2=false;
                    f3=false;
                }
        }
        if(!f1 && !f2 && !f3)ans+=0;
        else if((!f1 && !f2)||(!f1 && !f3) || (!f2 && !f3)||(!f1)||(!f2)||(!f3))ans+=1;
        else if((f1 && f2 && f3))ans+=2;
        ans+= temp*2;
        return ans;
    }
};