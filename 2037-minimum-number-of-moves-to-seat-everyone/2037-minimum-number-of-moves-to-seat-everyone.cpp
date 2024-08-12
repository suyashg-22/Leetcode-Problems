class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int moves = 0;
        int i=0;
        int j=0;
        while(i<seats.size()&& j<students.size()){
            if(seats[i]>students[j]){
                while(students[j]<seats[i]){
                    students[j]++;
                    moves ++;
                }
            }
            else if(seats[i]<students[j]){
                while(students[j]>seats[i]){
                    moves++;
                    students[j]--;
                }    
            }
            i++;
            j++;
        }
        return moves;
        
    }
};