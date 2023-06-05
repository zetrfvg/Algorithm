/*
因为后面的询问会把前面的询问覆盖，因此我们逆序处理询问，看看每个点上最后是哪些数字即可
如果修改的是某一列，则后续的询问中，所有对于行的修改，都会少修改一个位置
同样地，如果修改的是某一行，则后续的询问中，所有对于列的修改，都会少修改一个位置
因此我们用d1,d2两个变量来记录修改过了多少行和多少列
*/
class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<int> r(n),c(n);
        int d1=0,d2=0;
        int m=queries.size();
        long long ans=0;
        for(int i=m-1;~i;i--){
            int t=queries[i][0],j=queries[i][1],v=queries[i][2];
            if(t==0){
                if(r[j]) continue;
                ans+=1LL*v*(max(0,n-d1));
                d2++;
                r[j]=1;
            }else{
                if(c[j]) continue;
                ans+=1LL*v*(max(0,n-d2));
                d1++;
                c[j]=1;
            }
        }
        return ans;
    }
};
