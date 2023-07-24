/*
num1减去nums2*k后，等于若干个2的幂次和
这里枚举2的幂次和sum，sum=num1-num2*k
如果sum的二进制数中1的个数小于等于k，则说明存在合法的方案
*/
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(long long k=1;k<=1LL*num1-1LL*num2*k;k++){
            if(k>=__builtin_popcountll(1LL*num1-1LL*num2*k)) return k;
        }
        return -1;
    }
};
