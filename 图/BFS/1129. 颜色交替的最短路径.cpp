/*
标准BFS遍历
用st数组来记录是否存在路径，该路径最后一条边是红色/蓝色，来到达某个点
*/
class Solution {
  public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> ans(n,-1);
        vector<vector<int>> re(n),be(n);
        vector<vector<int>> st(n,vector<int>(2));
        for(auto &p:redEdges){
            re[p[0]].push_back(p[1]);
        }
        for(auto &p:blueEdges){
            be[p[0]].push_back(p[1]);
        }
        queue<tuple<int,int,int>> q;
        q.push({0,-1,0});
        while(!q.empty()){
            auto [x,c,d]=q.front();
            q.pop();
            if(ans[x]==-1) ans[x]=d;
            if(c!=0){
                for(auto &y:re[x]){
                    if(st[y][0]) continue;
                    st[y][0]=1;
                    q.push({y,0,d+1});
                }
            }
            if(c!=1){
                for(auto &y:be[x]){
                    if(st[y][1]) continue;
                    st[y][1]=1;
                    q.push({y,1,d+1});
                }
            }
        }
        return ans;
    }
};
