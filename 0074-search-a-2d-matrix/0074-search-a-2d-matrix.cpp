class Solution {
public:
    bool check2(vector<int>&arr,int t){
        int l=0;
        int h=arr.size()-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(arr[mid]==t)return true;
            else if(arr[mid]<t)l=mid+1;
            else h=mid-1;
        }
        return false;
    }
    int check(vector<int>&arr,int t){
        int m =arr.size();
        if(arr[0]<= t && t<=arr[m-1])return 1;
        else if(t<arr[0])return 0;
        return 2;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(check(matrix[mid],target)==1)return check2(matrix[mid],target);
            else if(check(matrix[mid],target)==0)h=mid-1;
            else l=mid+1;
        }
        return false;
    }
};