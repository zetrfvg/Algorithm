/*
观察结论的思维题
*/
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x=abs(sx-fx),y=abs(sy-fy);
        if(!x&&!y) return t!=1;
        return max(x,y)<=t;
    }
};
