/*
找割边模板题
*/
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        vector<int> h(n,-1),e(m*2),ne(m*2);
        vector<vector<int>> ans;
        vector<int> dfn(n),low(n);
        int time=0,idx=0;
        auto add=[&](int a,int b){
            e[idx]=b,ne[idx]=h[a],h[a]=idx++;
        };
        for(int i=0;i<m;i++){
            int a=connections[i][0],b=connections[i][1];
            add(a,b),add(b,a);
        }
        function<void(int,int)> tarjan=[&](int x,int from){
            dfn[x]=low[x]=++time;
            for(int i=h[x];~i;i=ne[i]){
                int y=e[i];
                if(!dfn[y]){
                    tarjan(y,i);
                    low[x]=min(low[x],low[y]);
                    if(low[y]>dfn[x]){
                        ans.push_back({x,y});
                    }
                }else if(i!=(from^1)) low[x]=min(low[x],dfn[y]);
            }
        };
        for(int i=0;i<n;i++) if(!dfn[i]) tarjan(i,-1);
        return ans;
    }
};
