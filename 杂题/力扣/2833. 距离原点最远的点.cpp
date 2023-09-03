/*
'_'要么全变L，要么全变R
*/
class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int x=0,y=0,z=0;
        for(auto c:s){
            if(c=='L') x++;
            else if(c=='R') y++;
            else z++;
        }
        return max(abs(x+z-y),abs(y+z-x));
    }
};
