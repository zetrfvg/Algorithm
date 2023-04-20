/*
搜索模拟题
*/
class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    char ds[4]={'l','r','u','d'};
    struct node{
        int x,y,d;
        string path;
        bool operator<(const node &b)const {
            return d==b.d?path>b.path:d>b.d;
        }
    };
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        //priority_queue<node,vector<node>,greater<node>> q;
        priority_queue<node> q;
        int n=maze.size(),m=maze[0].size();
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        dis[ball[0]][ball[1]]=0;
        q.push({ball[0],ball[1],0,""});
        while(!q.empty()){
            auto [x,y,d,path]=q.top();
            q.pop();
            if(x==hole[0]&&y==hole[1]){
                return path;
            }
            for(int i=0;i<4;i++){
                int xx=x,yy=y,nd=d;
                string npath=path+ds[i];
                while(xx+dx[i]>=0&&xx+dx[i]<n&&yy+dy[i]>=0&&yy+dy[i]<m&&!maze[xx+dx[i]][yy+dy[i]]){
                    xx+=dx[i];
                    yy+=dy[i];
                    nd++;
                    if(xx==hole[0]&&yy==hole[1]){
                        break;
                    }
                }
                if(d<nd&&nd<=dis[xx][yy]){
                    dis[xx][yy]=nd;
                    q.push({xx,yy,nd,npath});
                }
            }
        }
        return "impossible";
    }
};
