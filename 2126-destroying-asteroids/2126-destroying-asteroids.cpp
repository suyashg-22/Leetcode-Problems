using ll = long long;
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n =asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        ll x = mass;
        for(int i=0;i<n;i++){
            if(x<asteroids[i])return false;
            x+=asteroids[i];
        }
        return true;
    }
};