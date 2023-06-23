/*
试除法
*/
class Solution {
public:
    int kthFactor(int n, int k) {
        int t=0;
        for(int i=1;i<=n;i++){
            if(n%i==0&&(++t)==k){
                return i;
            }
        }
        return -1;
    }
};
