/*
细节模拟题
*/
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int c1=0,c2=0;
        for(auto s:board){
            for(auto c:s){
                c1+=c=='X';
                c2+=c=='O';
            }
        }
        auto check=[&](char ch){
            for(int i=0;i<3;i++){
                if((ch==board[0][i]&&ch==board[1][i]&&ch==board[2][i])||(ch==board[i][0]&&ch==board[i][1]&&ch==board[i][2])) return true;
            }
            return ((ch==board[0][0]&&ch==board[1][1]&&ch==board[2][2])||(ch==board[0][2]&&ch==board[1][1]&&ch==board[2][0]));
        };
        return !((c1!=c2&&c2!=c1-1)||(c2!=c1-1&&check('X'))||(c1!=c2&&check('O')));
    }
};
