/*
模拟
*/
class Solution {
public:
    int passThePillow(int n, int time) {
        int dir=1,p=1;
        while(time--){
            p+=dir;
            if(p==1||p==n) dir*=-1;
        }
        return p;
    }
};
