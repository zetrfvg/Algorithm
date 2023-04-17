/*
模拟过程，类似拓扑排序
*/
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n);
        vis[0]=1;
        queue<int> q;
        for(auto c:rooms[0]){
            q.push(c);
            vis[c]=1;
        }
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            for(auto y:rooms[x]){
                if(!vis[y]){
                    q.push(y);
                    vis[y]=1;
                }
            }
        }
        return accumulate(vis.begin(),vis.end(),0)==n;
    }
};
