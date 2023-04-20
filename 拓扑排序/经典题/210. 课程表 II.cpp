/*
拓扑排序模板题
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> e(numCourses);
        vector<int> deg(numCourses);
        for(auto &p:prerequisites){
            e[p[1]].push_back(p[0]);
            deg[p[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(!deg[i]){
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int y:e[x]){
                if(!--deg[y]){
                    q.push(y);
                    ans.push_back(y);
                }
            }
        }
        if(ans.size()!=numCourses){
            return {};
        }else{
            return ans;
        }
    }
};
