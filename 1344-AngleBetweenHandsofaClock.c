class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans;
        if(hour==12)hour=0;
        double h_angle=30*(double)hour+30*((double)minutes/60);
        double m_angle=360*((double)minutes/60);
         if(h_angle>=m_angle) ans=h_angle-m_angle;
         else ans=m_angle-h_angle;
        if (ans>180) ans=360-ans;
        return ans;
    }
};
