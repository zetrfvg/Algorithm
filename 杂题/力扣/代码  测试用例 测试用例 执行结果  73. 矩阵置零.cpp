/*
判断每一行每一列是否存在0，然后按行按列修改即可
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int> row(n),col(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!matrix[i][j]){
                    row[i]=1,col[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(row[i]){
                for(int j=0;j<m;j++) matrix[i][j]=0;
            }
        }
        for(int j=0;j<m;j++){
            if(col[j]){
                for(int i=0;i<n;i++) matrix[i][j]=0;
            }
        }
    }
};
