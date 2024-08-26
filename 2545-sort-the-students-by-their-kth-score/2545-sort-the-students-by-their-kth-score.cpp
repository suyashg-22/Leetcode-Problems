class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        
        int row= score.size();
        int col = score[0].size();
        
        sort(score.begin(),score.end(),[k](vector<int>&a,vector<int>&b){
            return a[k]>b[k];
        });
        
        return score;
    }
};