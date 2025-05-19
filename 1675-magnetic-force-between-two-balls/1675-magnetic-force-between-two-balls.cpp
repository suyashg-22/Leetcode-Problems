class Solution {
public:
    bool fun(vector<int>&arr,int m,int mid){
        int n = arr.size();
        int cnt =1;
        int last =arr[0];
        for(int i =0;i<n;i++){
            if(arr[i]-last >=mid){
                cnt+=1;
                last = arr[i];
            }
        }
        if(cnt>=m) return true;
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int low = 1;
        int high =position[n-1]-position[0];
        int ans =-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            bool flag = fun(position,m,mid);
            if(flag==true){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};