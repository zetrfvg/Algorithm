/*
对于节点x，其左儿子路径和为l，右儿子路径和为r
如果l!=r，则补足较小的那一端路径，答案累加上abs(l-r)
*/
class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans=0;
        function<int(int)> dfs=[&](int x){
            if(x>n) return 0;
            int l=dfs(x*2);
            int r=dfs(x*2+1);
            if(l!=r) ans+=abs(r-l);
            return cost[x-1]+max(l,r);
        };
        dfs(1);
        return ans;
    }
};
