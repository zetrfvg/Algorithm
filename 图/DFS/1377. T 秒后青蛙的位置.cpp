/*
①深搜的深度不超过t
②对于能向下搜且有儿子的节点，其pro=0
③叶子节点直接返回
*/
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> e(n);
        for(auto &p:edges){
            int x=p[0]-1,y=p[1]-1;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        vector<double> pro(n);
        function<void(int,int,int,double)> dfs=[&](int x,int fa,int dep,double p){
            pro[x]=p;
            if(dep==t) return;
            double cnt=0;
            for(auto y:e[x]){
                if(y!=fa) cnt+=1;
            }
            if(cnt>0){
                pro[x]=0;
                for(auto y:e[x]){
                    if(y!=fa){
                        dfs(y,x,dep+1,p/cnt);
                    }
                }
            }
        };
        dfs(0,-1,0,1);
        return pro[target-1];
    }
};
