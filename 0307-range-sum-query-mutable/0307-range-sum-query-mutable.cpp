using ll=long long;
class NumArray {
private:
    int n;
    vector<int>seg;
    void build(int ind,int low , int high,vector<int>&nums){
        if(low==high){
            seg[ind]=nums[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*ind+1,low,mid,nums);
        build(2*ind+2,mid+1,high,nums);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    int query(int ind,int low,int high,int left,int right){
        if(low>=left && right>=high)return seg[ind];
        if(right<low || high<left)return 0;
        int mid = (low+high)/2;
        int l = query(2*ind+1,low,mid,left,right);
        int r = query(2*ind+2,mid+1,high,left,right);
        return l+r;
    }
    void help(int ind,int low,int high,int index,int val){
        if(low==high && low==index){
            seg[ind]=val;
            return;
        }
        if(high<index || index<low)return;
        int mid = (low+high)/2;
        help(2*ind+1,low,mid,index,val);
        help(2*ind+2,mid+1,high,index,val);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
public:
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        seg.assign(4*n+1,0);
        build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        help(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */