/*
堆优化Dijkstra
*/
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> e(n);
        for(int i=0;i<edges.size();i++){
            e[edges[i][0]].push_back({edges[i][1],succProb[i]});
            e[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> pro(n);
        vector<int> vis(n);
        pro[start]=1;
        priority_queue<pair<double,int>> q;
        q.push({1.0,start});
        while(!q.empty()){
            auto [_,x]=q.top();
            q.pop();
            if(vis[x]) continue;
            vis[x]=1;
            for(auto &[y,p]:e[x]){
                if(!vis[y]&&pro[x]*p>pro[y]){
                    pro[y]=pro[x]*p;
                    q.push({pro[y],y});
                }
            }
        }
        return pro[end];
    }
};
