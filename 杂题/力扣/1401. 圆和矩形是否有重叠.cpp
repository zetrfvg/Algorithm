/*
暴力枚举矩形区域中的所有点是否存在圆内的点即可
*/
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                int dis=(i-xCenter)*(i-xCenter)+(j-yCenter)*(j-yCenter);
                if(dis<=radius*radius) return true;
            }
        }
        return false;
    }
};
