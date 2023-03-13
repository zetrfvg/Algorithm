/*
构造递推关系
[1 1][ F(n) ]=[F(n+1)]
[1 0][F(n-1)]=[ F(n) ]
*/
class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        vector<vector<int>> p{{1,1},{1,0}};
        vector<vector<int>> r{{1,0},{0,1}};
        auto mul=[](vector<vector<int>> &a,vector<vector<int>> &b){
            vector<vector<int>> res(2,vector<int>(2));
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    res[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j];
                }
            }
            return res;
        };
        auto quickpow=[&](int k){
            while(k){
                if(k&1) r=mul(r,p);
                p=mul(p,p);
                k>>=1;
            }
        };
        quickpow(n-1);
        return r[0][0];
    }
};
