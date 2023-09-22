/*
状态压缩，原地算法
对于每一位，用一个九位的二级制数来表示，最高以为表当前细胞的死活状态，后八位表示其周围八个方向的细胞是否存活，最后统一更新状态即可
*/
class Solution {
public:
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j]<<=8;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<8;k++){
                    int ii=i+dx[k],jj=j+dy[k];
                    if(ii<0||ii>=n||jj<0||jj>=m||!(board[ii][jj]>>8)) continue;
                    board[i][j]|=(1<<k);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int st=board[i][j]>>8;
                int cnt=__builtin_popcount(board[i][j])-st;
                if(st){
                    if(cnt>=2&&cnt<=3) board[i][j]=1;
                    else board[i][j]=0;
                }else{
                    if(cnt==3) board[i][j]=1;
                    else board[i][j]=0;
                }
            }
        }
    }
};
