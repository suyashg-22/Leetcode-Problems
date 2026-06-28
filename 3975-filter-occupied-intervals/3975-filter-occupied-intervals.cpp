class Solution {
public:

    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        int n = occupiedIntervals.size();
        auto fs = freeStart;
        auto fe = freeEnd;
        vector<vector<int>>brr;
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        vector<int>temp(2);
        temp[0]=occupiedIntervals[0][0];
        temp[1]=occupiedIntervals[0][1];
        for(int i=1;i<n;i++){
            int l = occupiedIntervals[i][0];
            int r = occupiedIntervals[i][1];

            int ll = temp[0];
            int rr = temp[1];
            if(rr+1>=l){
                temp[0]=min(l,ll);
                temp[1]=max(r,rr);
            }
            else{
                brr.push_back(temp);
                temp[0]=l;
                temp[1]=r;
            }
        }
        brr.push_back(temp);
        vector<vector<int>>ans;
        int m = brr.size();
        int i=0;
        while(i<m){
            int l = brr[i][0];
            int r = brr[i][1];
            if(r<fs){
                ans.push_back(brr[i]);
                i+=1;
            }
            else break;
        }
        int a =-1;
        int b =-1;
        while(i<m){
            int l = brr[i][0];
            int r = brr[i][1];
            if(fe<l)break;
            if(a==-1){
                a=l;
            }
            b=r;
            i+=1;
        }
        if(a!=-1){
            if(a<fs && fe<b){
                ans.push_back({a,fs-1});
                ans.push_back({fe+1,b});
            }
            else if(fe<b){
                ans.push_back({fe+1,b});
            }
            else if(a<fs){
                ans.push_back({a,fs-1});
            }
        }
        while(i<m){ans.push_back(brr[i]);i++;}
        return ans;
    }
};