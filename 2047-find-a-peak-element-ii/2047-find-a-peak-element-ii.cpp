class Solution {
public:
    int maxindex(vector<vector<int>>& mat, int mid){
        int maxi=INT_MIN;
        int maxindex =-1;
        for(int i =0;i<mat.size();i++){
            if(mat[i][mid]>maxi){
                maxindex =i;
                maxi = mat[i][mid];
            }
        }
        return maxindex;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m =mat[0].size();
        int low =0;
        int high = m-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int maxrow = maxindex(mat,mid);
            int el = mat[maxrow][mid];
            int left,right;
            if(mid+1<m) right=mat[maxrow][mid+1];
            else right =-1;
            if(mid-1 >=0) left = mat[maxrow][mid-1];
            else left =-1;
            if(el>left && el >right){
                return{maxrow,mid};
            }
            else if( el<left) high =mid-1;
            else low =mid+1;
        }
        return{-1,-1};
    }
};