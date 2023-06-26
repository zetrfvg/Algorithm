/*
哈希表记录所有人的败场数即可
*/
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> g;
        vector<vector<int>> ans(2);
        for(auto c:matches){
            g[c[0]]+=0;
            g[c[1]]+=1;
        }
        for(auto &[a,b]:g){
            if(!b) ans[0].push_back(a);
            if(b==1) ans[1].push_back(a);
        }
        return ans;
    }
};
