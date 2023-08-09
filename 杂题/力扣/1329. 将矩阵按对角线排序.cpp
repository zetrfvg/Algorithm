/*
枚举出所有对角线，对对角线上的元素排序后再依次放入矩阵中即可
*/
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            vector<int> p;
            for(int x=i,y=0;x<n&&y<m;x++,y++){
                p.push_back(mat[x][y]);
            }
            sort(p.begin(),p.end());
            for(int x=i,y=0,j=0;x<n&&y<m;x++,y++,j++){
                mat[x][y]=p[j];
            }
        }
        for(int i=0;i<m;i++){
            vector<int> p;
            for(int x=0,y=i;x<n&&y<m;x++,y++){
                p.push_back(mat[x][y]);
            }
            sort(p.begin(),p.end());
            for(int x=0,y=i,j=0;x<n&&y<m;x++,y++,j++){
                mat[x][y]=p[j];
            }
        }
        return mat;
    }
};
