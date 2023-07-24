/*
公式解法
*/
class Solution {
public:
    int longestString(int x, int y, int z) {
        return (z+min(x,y)*2+(x!=y))*2;
    }
};
