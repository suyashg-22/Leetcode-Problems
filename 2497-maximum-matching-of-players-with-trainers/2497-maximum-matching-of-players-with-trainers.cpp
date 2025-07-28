class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n= players.size();
        int m = trainers.size();
        int cnt =0;
        int i=0;
        int j =0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        while(i<n && j<m){
            if(players[i]<=trainers[j]){
                cnt+=1;
                i+=1;
                j+=1;
            }
            else{
                j+=1;
            }
        }
        return cnt;
    }
};