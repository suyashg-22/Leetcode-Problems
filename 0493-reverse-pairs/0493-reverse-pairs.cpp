class Solution {
public:
    int ans =0;
    
    void ms(int l,int r, vector<int>&arr){
        if(l>=r)return;
        int m = (l+r)/2;
        ms(l,m,arr);
        ms(m+1,r,arr);
        
        int a=l;
        int b=m+1;
        while(a<=m){
            while(b<=r && arr[a]> 2LL*arr[b]){
                b++;
            }
            ans+= b-m-1;
            a++;
        }
        vector<int>temp;
        int i=l;
        int j=m+1;
        while(i<=m && j<=r){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<=m){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=r){
            temp.push_back(arr[j]);
            j++;
        }
        int ind =0;
        for(int i=l;i<=r;i++){
            arr[i]=temp[ind];
            ind++;
        }
        return;
    }

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        ms(0,n-1,nums);
        return ans;
    }
};