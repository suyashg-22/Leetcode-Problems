class Solution {
public:
    vector<int>*arr;
    int target;
    int n;

    bool check(int l,int h,int mid){

        if((*arr)[l]<= (*arr)[mid]){
            if(target>= (*arr)[l] && target<=(*arr)[mid])return 0;
            return 1;
        }
        else{
            if(target>=(*arr)[mid+1] && target <= (*arr)[h])return 1;
            return 0;
        }
    }

    int bs(){
        int l =0;
        int h =n-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if((*arr)[mid]==target)return mid;

            if(check(l,h,mid)){
                l=mid+1;
            }
            else h=mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        this->arr=&nums;
        this->target= target;
        this->n=nums.size();
        return bs();
    }
};