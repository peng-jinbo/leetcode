class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        double x= 0.5*(x1+x2),y=0.5*(y1+y2);
        double lenx = x2-x1,leny = y2-y1;
        double disx = abs(x_center-x);
        double disy = abs(y_center-y);
        double dis = max(disx-lenx/2,0.0)*max(disx-lenx/2,0.0)+max(disy-leny/2,0.0)*max(disy-leny/2,0.0);
        return dis<=radius*radius;
    }
};
