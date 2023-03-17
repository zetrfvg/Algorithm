/*
二维前缀和模板题
*/
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> s(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+mat[i-1][j-1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int a=max(0,i-k-1),b=max(0,j-k-1),c=min(n,i+k),d=min(m,j+k);
                mat[i-1][j-1]=s[c][d]-s[c][b]-s[a][d]+s[a][b];
            }
        }
        return mat;
    }
};
