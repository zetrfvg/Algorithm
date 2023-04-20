/*
拓扑排序套拓扑排序
为了方便处理，给所有不属于任何组的任务强行添加一个组，如第0、2、7三个任务不属于任何组，但当前有0、1两个组，则让他们分别属于2、3、4三个组
建图
枚举beforeItems中的边，如果两个任务属于同一组，则在组内任务之间建边；如果属于不同组，则在这两个任务所在的组之间建一条边
对组进行拓扑排序，当前第idx出队，则再在这个第idx组内的任务进行拓扑排序
*/
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(auto &g:group){
            if(g==-1) g=m++;
        }
        vector<vector<int>> item(m);
        for(int i=0;i<n;i++){
            item[group[i]].push_back(i);
        }
        vector<int> item_deg(n),group_deg(m);
        vector<vector<int>> item_e(n),group_e(m);
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(auto j:beforeItems[i]){
                if(group[i]==group[j]){
                    item_e[j].push_back(i);
                    item_deg[i]++;
                }else{
                    group_e[group[j]].push_back(group[i]);
                    group_deg[group[i]]++;
                }
            }
        }
        auto topo_sort=[&](int idx){
            int cnt=0;
            queue<int> q;
            for(int i=0;i<item[idx].size();i++){
                if(!item_deg[item[idx][i]]){
                    q.push(item[idx][i]);
                }
            }
            while(!q.empty()){
                int x=q.front();
                q.pop();
                ans.push_back(x);
                cnt++;
                for(auto &y:item_e[x]){
                    if(!--item_deg[y]){
                        q.push(y);
                    }
                }
            }
            return cnt!=item[idx].size();
        };
        queue<int> q;
        for(int i=0;i<m;i++){
            if(!group_deg[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            if(topo_sort(x)){
                return {};
            }
            for(auto &y:group_e[x]){
                if(!--group_deg[y]){
                    q.push(y);
                }
            }
        }
        if(ans.size()==n){
            return ans;
        }else{
            return {};
        }
    }
};
