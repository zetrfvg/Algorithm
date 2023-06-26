class Solution {
public:
    int pivotInteger(int n) {
        int x=sqrt((n*n+n)/2);
        if(x*x==(n*n+n)/2) return x;
        else return -1;
    }
};
