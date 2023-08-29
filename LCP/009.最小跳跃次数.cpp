/*
BFS搜素，用x点来更新到x+jump[x]点的最小操作次数
用一个far来维护走过的最远的点
BFS搜索到x点时，如果far<x，则枚举[far,x]之间的这一段点，如果已经走过则忽略，否则到达该点的最小操作次数为到达x点的操作次数再加1
*/
class Solution {
public:
    int minJump(vector<int>& jump) {
        int n=jump.size();
        unordered_map<int,int> p;
        queue<int> q;
        p[0]=1;
        q.push(0);
        int far=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            if(x+jump[x]>=n) return p[x];
            if(!p.count(x+jump[x])){
                p[x+jump[x]]=p[x]+1;
                q.push(x+jump[x]);
            }
            while(far<=x){
                if(!p.count(far)){
                    p[far]=p[x]+1;
                    q.push(far);
                }
                far++;
            }
        }
        return -1;
    }
};
