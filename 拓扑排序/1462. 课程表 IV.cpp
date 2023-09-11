/*
拓扑排序
对于每一个课程，递推的推出每个课程所有的先决课程即可，每个课程用一个哈希表维护
*/
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<unordered_set<int>> p(numCourses);
        vector<bool> ans(queries.size());
        vector<int> e[numCourses];
        vector<int> deg(numCourses,0);
        for(auto t:prerequisites){
            e[t[0]].push_back(t[1]);
            deg[t[1]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(!deg[i]) q.push(i);
        }
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            for(auto y:e[x]){
                p[y].insert(x);
                for(auto g:p[x]) p[y].insert(g);
                if(!--deg[y]) q.push(y);
            }
        }
        for(int i=0;i<queries.size();i++){
            ans[i]=p[queries[i][1]].count(queries[i][0]);
        }
        return ans;
    }
};
