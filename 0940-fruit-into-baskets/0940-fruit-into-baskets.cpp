class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int temp1= -1;
        int temp2 =-1;
        int maxi =0;
        bool f1=false,f2=false;
        for(int i=0;i<n;i++){
            int j=i+1;
            temp1 = fruits[i];
            while(j<n){
                if(temp2==-1 && fruits[j]!=temp1){
                    temp2 = fruits[j];
                }
                if(fruits[j]!=temp1 && fruits[j]!=temp2){
                    maxi =max(maxi,j-i);
                    temp1 =-1;
                    temp2=-1;
                    break;
                }
                j+=1;
            }
            maxi=max(maxi,j-i);
            if(maxi>=n-i)break;
        }
        return maxi;
    }
};