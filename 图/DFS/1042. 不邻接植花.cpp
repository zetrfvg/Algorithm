/*
dfs整个图
用一个二进制数来表示他连接的所有种过花的节点有哪些类型，如5=0101表示他的邻居中已经种过第1和第3种花，我们随机取一个合法的花种下即可，这里选最低为，即为第2种花
*/
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> e(n);
        vector<int> ans(n);
        for(auto p:paths){
           int x=--p[0],y=--p[1];
           e[x].push_back(y);
           e[y].push_back(x);
        }
        function<void(int)> dfs=[&](int x){
            int st=0;
            for(auto y:e[x]) if(ans[y]) st|=(1<<(ans[y]-1));
            for(int i=0;i<4;i++){
                if(!((st>>i)&1)){
                    ans[x]=i+1;
                    break;
                }
            }
            for(auto y:e[x]) if(!ans[y]) dfs(y);
        };
        for(int i=0;i<n;i++) if(!ans[i]) dfs(i);
        return ans;
    }
};
