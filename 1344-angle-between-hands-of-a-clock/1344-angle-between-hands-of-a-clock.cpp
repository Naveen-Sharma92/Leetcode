class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans = abs(30 * hour + 0.5 * minutes - 6 * minutes);
        return min(ans,360-ans);
    }
};