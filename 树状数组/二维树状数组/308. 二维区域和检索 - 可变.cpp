/*
二维树状数组模板题
*/
class NumMatrix {
public:
    vector<vector<int>> mat,tr;
    int lowbit(int x){
        return x&-x;
    }
    int query(int row,int col){
        int res=0;
        for(int i=row;i;i-=lowbit(i)){
            for(int j=col;j;j-=lowbit(j)){
                res+=tr[i][j];
            }
        }
        return res;
    }
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        mat.assign(n,vector<int>(m));
        tr.assign(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                update(i,j,matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int diff=val-mat[row][col];
        mat[row][col]=val;
        for(int i=row+1;i<tr.size();i+=lowbit(i)){
            for(int j=col+1;j<tr[0].size();j+=lowbit(j)){
                tr[i][j]+=diff;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return query(row2+1,col2+1)-query(row1,col2+1)-query(row2+1,col1)+query(row1,col1);
    }
};
