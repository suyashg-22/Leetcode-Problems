class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans =0;
        int n = tasks.size();
        sort(tasks.begin(),tasks.end());
        int prev=0;
        for(int i=1;i<n;i++){
            if(tasks[i]!=tasks[i-1]){
                if(i-prev==1){
                    return -1;
                }
                else{
                    int x = i-prev;
                    if(x%3==2){
                        x-=1;
                    }
                    else if(x%3==0){
                        x-=2;
                    }
                    ans+= ((x-1)/3)+1;
                    prev= i;
                }
            }
        }
        if(n-prev==1){
            return -1;
        }
        int x = n-prev;
        if(x%3==2){
            x-=1;
        }
        else if(x%3==0){
            x-=2;
        }
        ans+= ((x-1)/3)+1;
        prev= n;
        return ans;
    }
};