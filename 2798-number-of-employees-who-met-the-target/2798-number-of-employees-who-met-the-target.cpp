class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        
        sort(hours.begin(),hours.end(),greater<int>());
        int count =0;
        
        for(int i=0;i<hours.size();i++){
            if(hours[i]>=target){
                count++;
            }
            else{
                break;
            }
        }
        
        return count;
    }
};