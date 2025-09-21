class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>arr(n,0);
        if(n==1)return {0};
        if(n%2==1){
            arr[n/2]=0;
        }
        int temp = -1*(n/2) ;
        int mid = n/2;
        for(int i=0;i<n;i++){
            if(i==mid && n%2==0){
                temp+=1;
            }
            arr[i]=temp;
            temp+=1;
        }
        return arr;
    }
};