/*
简单dfs应用题
*/
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n=pid.size();
        unordered_map<int,int> p;
        int rt=0;
        vector<vector<int>> e(n);
        for(int i=0;i<n;i++){
            p[pid[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(!ppid[i]) rt=i;
            else e[p[ppid[i]]].push_back(i);
        }
        vector<int> ans;
        function<void(int,int)> dfs=[&](int x,int st){
            if(x==p[kill]) st=1;
            if(st) ans.push_back(pid[x]);
            for(auto y:e[x]) dfs(y,st);
        };
        dfs(rt,0);
        return ans;
    }
};
