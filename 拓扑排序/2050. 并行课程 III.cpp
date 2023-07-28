/*
拓扑排序+小根堆
某一课程的最早开始时间取决于它的所有前驱课程中最晚的结束时间
考虑这一DAG上的状态转移即可
*/
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time){
        vector<vector<int>> g(n);
        vector<int> deg(n,0);
        for(auto &p:relations){
            int x=p[0]-1,y=p[1]-1;
            g[x].push_back(y);
            deg[y]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i=0;i<n;i++) if(!deg[i]) q.push({time[i],i});
        int ans=0;
        while(!q.empty()){
            auto [t,x]=q.top();
            q.pop();
            ans=t;
            for(auto y:g[x]) if(!--deg[y]) q.push({t+time[y],y});
        }
        return ans;
    }
};
