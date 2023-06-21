/*
考虑长度为n的串，如果k位于后半位置，则说明进行了一次翻转，这时令k-=串长/2
接下来考虑的就是长为n/2的串，位于第k个位置的符号是什么
由此递推直到n=1，统计翻转的次数即可
*/
class Solution {
public:
    int kthGrammar(int n, int k) {
        int len=1<<(n-1);
        int rev=0;
        while(n>1){
            if(k>len/2) k-=len/2,rev^=1;
            n--,len>>=1;
        }
        return rev;
    }
};
