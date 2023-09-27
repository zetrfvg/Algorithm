/*
首先找到第一个开着的门
考虑向右移动k次，遇到关着的门就跳过，遇到开着的门就关上，答案为最后一扇开着的门的位置
*/
class Solution {
public:
    int houseCount(Street* street, int k) {
        while(!street->isDoorOpen()) street->moveRight();
        int ans=1;
        for(int i=1;i<=k;i++){
            street->moveRight();
            if(street->isDoorOpen()){
                ans=i;
                street->closeDoor();
            }
        }
        return ans;
    }
};
