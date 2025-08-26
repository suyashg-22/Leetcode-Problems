class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        double maxid =-1.0;
        int maxia = -1;
        for(int i=0;i<n;i++){

            double temp = 1.0*dimensions[i][0]*dimensions[i][0] + (1.0*dimensions[i][1]*dimensions[i][1]);
            double d= sqrt(temp);
            int a= dimensions[i][0]*dimensions[i][1];
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