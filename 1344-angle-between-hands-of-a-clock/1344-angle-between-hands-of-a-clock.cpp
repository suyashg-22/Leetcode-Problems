class Solution {
public:
    double angleClock(int hour, int minutes) {
        int hmin = (hour%12)*60 +minutes;
        int mmin = minutes;
        double a = hmin*0.5;
        double b = mmin*6.0;
        double ans = abs(b-a);
        return min(ans,abs(360-ans));
        
    }
};