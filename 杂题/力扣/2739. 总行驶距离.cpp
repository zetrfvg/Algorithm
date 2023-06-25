/*
简单模拟
*/
class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int res=0;
        for(int i=1;mainTank;mainTank--,i++){
            res+=10;
            if(i%5==0&&additionalTank) mainTank++,additionalTank--;
        }
        return res;
    }
};
