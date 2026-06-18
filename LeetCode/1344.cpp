class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle = 30 * hour - 5.5 * minutes;
        if (angle < 0) {
            angle += 360;
        }
        return min(angle, 360 - angle);
    }
};