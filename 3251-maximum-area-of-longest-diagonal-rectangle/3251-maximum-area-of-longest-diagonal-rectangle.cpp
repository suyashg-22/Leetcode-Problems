class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        auto arr = dimensions;
        int n = arr.size();
        double maxid =0;
        int maxia = 0;
        for(int i=0;i<n;i++){
            double temp = pow(arr[i][0],2) + pow(arr[i][1],2);
            double d= pow(temp,0.5);
            int a= arr[i][0]*arr[i][1];
            if(d>maxid){
                maxid=d;
                maxia=a;
            }
            else if(d==maxid){
                maxia = max(maxia,a);
            }
        }
        return maxia;
    }
};