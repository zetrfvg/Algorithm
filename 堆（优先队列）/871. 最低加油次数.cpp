/*
用一个堆来维护走过的加油站
基于贪心
如果走到最远的距离，则从走过的加油站中选一个油最多的进行加油
*/
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> q;
        int ans=0,cur=startFuel;
        stations.push_back({target,0});
        int n=stations.size();
        for(int i=0;i<n;i++){
            if(stations[i][0]<=cur){
                q.push(stations[i][1]);
            }else{
                while(!q.empty()&&cur<stations[i][0]){
                    cur+=q.top();
                    ans++;
                    q.pop();
                }
                if(cur<stations[i--][0]) break;
            }
        }
        return cur>=target?ans:-1;
    }
};
