/*
阶乘中容易知道2的数量是比5多的，因此阶乘后尾随0的数量取决于1~n中有多少个因子5
1、令n=n/5，得到1~n中有n/5个数存在因子5
2、继续令n=n/5，得到1~n中有n/5个数存在因子25
3、···
直到n为0，此时没有能够贡献更大的5的幂的因子的数
答案为累加
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        while(n){
            n/=5;
            ans+=n;
        }
        return ans;
    }
};
