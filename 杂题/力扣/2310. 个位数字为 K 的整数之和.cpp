/*
枚举可以划分为若干个以k结尾的数字的个数
*/
class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(!num) return 0;
        for(int i=1;i<=num;i++){
            int p=num-k*i;
            if(p>=0&&p%10==0) return i;
        }
        return -1;
    }
};
