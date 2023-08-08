/*
因为可以无限交换次数，因此可以认为能够同时对任意两点进行乘-1的操作
如果负数的数量是偶数，则答案为矩阵中所有元素的绝对值和
如果负数的数量是奇数，则答案为矩阵中所有元素的绝对值和（除去减去绝对值最小的元素）
*/
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0,mn=1e18,cnt=0;
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cnt+=matrix[i][j]<0;
                mn=min(mn,1LL*abs(matrix[i][j]));
                sum+=abs(matrix[i][j]);
            }
        }
        if(cnt&1) sum-=mn*2;
        return sum;
    }
};
