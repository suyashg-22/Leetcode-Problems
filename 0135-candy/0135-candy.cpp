class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<pair<bool,bool>>temp(n,{0,0});
        for(int i=0;i<n;i++){
            if(i==0){
                if(i+1<n && ratings[i]>ratings[i+1])temp[i].second=1;
            }
            else if(i==n-1){
                if(i-1>=0 && ratings[i-1]<ratings[i])temp[i].first=1;
            }
            else{
                if(ratings[i-1]<ratings[i] && ratings[i]>ratings[i+1]){
                    temp[i] = {1,1};
                }
                else if(ratings[i-1]<ratings[i])temp[i].first=1;
                else if(ratings[i]>ratings[i+1])temp[i].second=1;
            }
        }
        vector<pair<int,int>>arr(n,{0,0});
        for(auto it:temp){
            cout<<it.first<<" "<<it.second<<"    ";
        }
        cout<<endl;
        int last=n-1;
        for(int i=n-1;i>=0;i--){
            if(temp[i].second==0){
                last=i;
            }
            arr[i].second=last;
        }
        last =0;
        for(int i=0;i<n;i++){
            if(temp[i].first==0){
                last=i;
            }
            arr[i].first=last;
        }
        int ans =0;
        for(int i=0;i<n;i++){
            int maxi = max(abs(i-arr[i].first),abs(i-arr[i].second));
            ans += (maxi+1);
        }
        return ans;
    }
};