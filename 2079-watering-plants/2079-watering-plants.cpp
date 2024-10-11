class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n= plants.size();
        int steps = 0;
        int i =0;
        int water = capacity;
        for(int i=0;i<n;i++){
            if(water>=plants[i]){
                steps++;
                water=water-plants[i];
            }
            else {
                steps+=1+(i)*2;
                water=capacity-plants[i];
            }
        }

        return steps;
    }
};