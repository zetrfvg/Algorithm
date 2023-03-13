/*
构造递推关系
[1 1 1][ F(n) ] [F(n+1)]
[1 0 0][F(n-1)]=[ F(n) ]
[0 1 0][F(n-2)] [F(n-1)]
*/
class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n<=2) return 1;
        vector<vector<long>> p{{1,1,1},{1,0,0},{0,1,0}};
        vector<vector<long>> r{{1,0,0},{0,1,0},{0,0,1}};
        auto mul=[](vector<vector<long>> a,vector<vector<long>> b){
            vector<vector<long>> res(3,vector<long>(3));
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    res[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j]+a[i][2]*b[2][j];
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
        quickpow(n-2);
        return r[0][0]+r[0][1];
    }
};
