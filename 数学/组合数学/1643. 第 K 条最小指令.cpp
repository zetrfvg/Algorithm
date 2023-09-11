/*
向右走为H，向左走为V，要字典序最小，每次考虑走的时候优先考虑能否向右走
向右走一格后，到达终点的方案数为C(h+v-1,h-1);
向下走一格后，到达终点的方案数为C(h+v-1,h);
如果剩余的K<=C(h+v-1,h-1)，说明此时应当向右走；否则只能向左右，剩下模拟即可
*/
class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int n=destination[0],m=destination[1];
        vector<vector<int>> comb(n+m,vector<int>(m));
        comb[0][0]=1;
        for(int i=1;i<n+m;i++){
            comb[i][0]=1;
            for(int j=1;j<=i&&j<m;j++){
                comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
            }
        }
        string ans;
        for(int i=0,mx=n+m;i<mx;i++){
            if(m>0){
                int c=comb[n+m-1][m-1];
                if(k>c){
                    ans+='V';
                    n--,k-=c;
                }else{
                    ans+='H';
                    m--;
                }
            }else{
                ans+='V';
                n--;
            }
        }
        return ans;
    }
};
