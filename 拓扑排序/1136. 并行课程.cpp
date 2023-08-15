/*
BFS拓扑排序，BFS的层数即为答案
*/
class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> deg(n);
        vector<vector<int>> e(n);
        for(auto &re:relations){
            re[0]--,re[1]--;
            e[re[0]].push_back(re[1]);
            deg[re[1]]++;
        }
        int ans=0,cnt=0;
        queue<int> q;
        for(int i=0;i<n;i++) if(!deg[i]) q.push(i);
        while(!q.empty()){
            ans++;
            int sz=q.size();
            while(sz--){
                int x=q.front();
                q.pop();
                cnt++;
                for(auto y:e[x]) if(!--deg[y]) q.push(y);
            }
        }
        return cnt==n?ans:-1;
    }
};
