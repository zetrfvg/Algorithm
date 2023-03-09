class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vector<int>> g(n);
        vector<int> deg(n),vis(n);
        for(auto p:edges){
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
            deg[p[0]]++,deg[p[1]]++;
        }
        queue<int> q;
        int cnt=n;
        for(int i=0;i<n;i++){
            if(deg[i]==1){
                q.push(i);
            }
        }
        while(cnt>2){
            int sz=q.size();
            while(sz--){
                int x=q.front();
                q.pop();
                cnt--;
                for(int y:g[x]){
                    if(--deg[y]==1) q.push(y);;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
