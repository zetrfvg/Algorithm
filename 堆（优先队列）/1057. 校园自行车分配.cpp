/*
枚举所有的工人-自行车对，每次选取曼哈顿距离最小的一对来匹配，这里用到了小根堆
*/
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n=workers.size(),m=bikes.size();
        vector<int> ans(n,-1),vis(m);
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int d=abs(workers[i][0]-bikes[j][0])+abs(workers[i][1]-bikes[j][1]);
                q.push({d,i,j});
            }
        }
        while(!q.empty()){
            auto [d,i,j]=q.top();
            q.pop();
            if(ans[i]==-1&&!vis[j]) ans[i]=j,vis[j]=1;
        }
        return ans;
    }
};
