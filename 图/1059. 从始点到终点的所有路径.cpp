/*
建反图，从终点开始跑拓扑序
*/
class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> e(n);
        vector<int> deg(n);
        for(auto &p:edges){
            e[p[1]].push_back(p[0]);
            deg[p[0]]++;
        }
        if(deg[destination]) return false;
        queue<int> q;
        q.push(destination);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            if(x==source) return true;
            for(auto y:e[x]) if(!--deg[y]) q.push(y);
        }
        return false;
    }
};
