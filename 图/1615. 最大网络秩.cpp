/*
首先统计各个城市的度，并找出度的最大值first和次大值second
找到所有度等于first城市和度等于second的城市
1、如果度等于最大值的城市只有一个，则枚举次大值城市，
如果存在不直接和最大值城市相连的次大值城市，则返回first+second
否则返回first+second-1
2、如果度等于最大值的城市不止一个，则枚举最大值城市，
如果存在两个最大值城市不直接相连，则返回first*2
否则返回first*2-1
*/
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int m=roads.size();
        vector<unordered_set<int>> g(n);
        vector<int> deg(n);
        int first=-1,second=-1;
        for(int i=0;i<m;i++){
            g[roads[i][0]].insert(roads[i][1]);
            g[roads[i][1]].insert(roads[i][0]);
            deg[roads[i][0]]++,deg[roads[i][1]]++;
        }
        for(int i=0;i<n;i++){
            if(deg[i]>first){
                second=first;
                first=deg[i];
            }else if(deg[i]>second){
                second=deg[i];
            }
        }
        vector<int> fi,se;
        for(int i=0;i<n;i++){
            if(deg[i]==first) fi.push_back(i);
            if(deg[i]==second) se.push_back(i);
        }
        if(fi.size()==1){
            int x=fi[0];
            for(auto y:se){
                if(!g[x].count(y)){
                    return first+second;
                }
            }
            return first+second-1;
        }else{
            for(auto x:fi){
                for(auto y:fi){
                    if(x!=y&&!g[x].count(y)){
                        return first*2;
                    }
                }
            }
            return first*2-1;
        }
    }
};
