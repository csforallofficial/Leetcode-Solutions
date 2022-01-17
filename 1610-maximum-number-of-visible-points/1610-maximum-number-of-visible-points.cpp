class Solution 
{
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) 
    {
        auto locx = location[0];
        auto locy = location[1];
        
        vector<double> angles;
        for (auto& point : points)
        {
            if (point[0] == locx && point[1] == locy)
                continue;
            
            auto angle = calcAngle(locx, locy, point[0], point[1]);
            angles.push_back(angle);
        }
        
        auto pointInLocation = points.size() - angles.size();
        
        sort(begin(angles), end(angles));
        
        auto maxPoints = 0;
        for (int i = 0; i < angles.size(); i++)
        {
            auto startAngle = angles[i];
            auto endAngle = startAngle + angle;
            auto pointInAngle = pointsCountInAngle(angles, startAngle, min(endAngle, 360.0));
            if (endAngle >= 360)
                pointInAngle += pointsCountInAngle(angles, 0, endAngle - 360);
            
            maxPoints = max(pointInAngle, maxPoints);
        }
        
        return maxPoints + pointInLocation;
    }
    
private:    
    int pointsCountInAngle(vector<double>& sortedAngles, double startA, double endA)
    {        
        auto lower = lower_bound(begin(sortedAngles), end(sortedAngles), startA);
        auto upper = upper_bound(begin(sortedAngles), end(sortedAngles), endA + 1e-5);
        auto dist = distance(lower, upper);
        return dist;
    }
    
    double calcAngle(int locx, int locy, int x, int y)
    {
        int vx = x - locx;
        int vy = y - locy;
        
        double vlen = sqrt(vx * vx + vy * vy);
        auto cosangle = vx / vlen;
        
        auto angle = acos(cosangle) / M_PI * 180;       
        if (vy < 0)
            angle = 360 - angle;
        
        return angle;
    }
};