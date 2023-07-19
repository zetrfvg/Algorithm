/*
模拟题
*/
class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    static const int D=60001;
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> st;
        for(auto &ob:obstacles) st.insert(ob[0]*D+ob[1]);
        int x=0,y=0,dir=0,ans=0;
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-2) dir=(dir+3)%4;
            else if(commands[i]==-1) dir=(dir+1)%4;
            for(int j=0;j<commands[i];j++){
                int xx=x+dx[dir],yy=y+dy[dir];
                if(st.count(xx*D+yy)) break;
                x=xx,y=yy;
                ans=max(xx*xx+yy*yy,ans);
            }
        }
        return ans;
    }
};
