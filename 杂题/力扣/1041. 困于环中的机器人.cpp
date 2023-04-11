/*
结论：执行完指令之后，必须是不位于原点且方向朝北。
*/
class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> dx{{0,1},{-1,0},{0,-1},{1,0}};
        int x=0,y=0,dir=0;
        for(auto c:instructions){
            if(c=='G'){
                x+=dx[dir][0],y+=dx[dir][1];
            }else if(c=='L'){
                dir=(dir+3)%4;
            }else{
                dir=(dir+1)%4;
            }
        }
        return dir||(x==0&&y==0);
    }
};
