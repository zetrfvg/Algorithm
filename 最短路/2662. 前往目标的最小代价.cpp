/*
建图：
记起点为(sx,sy)，终点为(tx,ty)
离散化，坐标(i,j)转化为一维坐标i*D+j，D表示一个较大的偏移量
对于给定的一条特殊路径e[i]=[x1,y1,x2,y2,w]，先令w=min(w,abs(x1-x2)+abs(y1-y2))
然后连三条边，从(x1,y1)到(x2,y2)，从(sx,sy)到(x1,y1)，从(x1,y1)到(tx,ty)
再枚举除e[i]之外的其他路径e[j]=[x3,y3,x4,y4,w']
连两条边，从(x2,y2)到(x3,y3),从(x4,y4)到(x1,y1)

建图之后跑一遍dijkstra即可
*/
class Solution {
public:
    static const int D=1e5+10;
    int minimumCost(vector<int>& s, vector<int>& t, vector<vector<int>>& e) {
        unordered_map<long long,int> g;
        int idx=0;
        g[1LL*s[0]*D+s[1]]=idx++;
        g[1LL*t[0]*D+t[1]]=idx++;
        if(1LL*s[0]*D+s[1]==1LL*t[0]*D+t[1]) return 0;
        for(int i=0;i<e.size();i++){
            int a=e[i][0],b=e[i][1],c=e[i][2],d=e[i][3];
            if(!g.count(1LL*a*D+b)){
                g[1LL*a*D+b]=idx++;
            }
            if(!g.count(1LL*c*D+d)){
                g[1LL*c*D+d]=idx++;
            }
        }
        auto get=[&](int x,int y){
            return g[1LL*x*D+y];
        };
        vector<vector<pair<int,int>>> ed(idx);
        ed[0].push_back({1,abs(s[0]-t[0])+abs(s[1]-t[1])});
        auto add=[&](int a,int b,int c,int d,int w){
            ed[get(a,b)].push_back({get(c,d),w});
        };
        for(int i=0;i<e.size();i++){
            int a=e[i][0],b=e[i][1],c=e[i][2],d=e[i][3],w=min(e[i][4],abs(a-c)+abs(b-d));
            add(a,b,c,d,w);
            add(s[0],s[1],a,b,abs(s[0]-a)+abs(s[1]-b));
            add(c,d,t[0],t[1],abs(t[0]-c)+abs(t[1]-d));
            for(int j=0;j<e.size();j++){
                if(i==j) continue;
                int aa=e[j][0],bb=e[j][1],cc=e[j][2],dd=e[j][3];
                add(cc,dd,a,b,abs(cc-a)+abs(dd-b));
                add(c,d,aa,bb,abs(c-aa)+abs(d-bb));
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,0});
        vector<int> d(idx,1e9),vis(idx);
        d[0]=0;
        while(!q.empty()){
            auto [_,x]=q.top();
            q.pop();
            if(vis[x]) continue;
            vis[x]=1;
            for(auto &[y,w]:ed[x]){
                if(!vis[y]&&d[x]+w<d[y]){
                    d[y]=d[x]+w;
                    q.push({d[y],y});
                }
            }
        }
        return d[1];
    }
};
