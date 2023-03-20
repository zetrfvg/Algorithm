/*
首先对数组进行排序
假设已经可以构造出区间[0,sum]中的所有元素
那么下一个要构造的数为sum+1，而一旦我们枚举的下一个元素coins[i]>sum+1，则说明不可构造出来
*/
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int sum=0;
        int n=coins.size();
        sort(coins.begin(),coins.end());
        for(int i=0;i<n;i++){
            if(sum+1<coins[i]) break;
            sum+=coins[i];
        }
        return sum+1;
    }
};
