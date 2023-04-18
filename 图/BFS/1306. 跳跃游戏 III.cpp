/*
BFS搜索即可
*/
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> vis(n);
        vis[start]=1;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            if(!arr[x]) return true;
            for(auto dx:{-1,1}){
                int nx=x+dx*arr[x];
                if(nx<0||nx>=n||vis[nx]) continue;
                vis[nx]=1;
                q.push(nx);
            }
        }
        return false;
    }
};
