/*
bitset求三元环数量
*/
class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        vector<bitset<1010>> e(n);
        for(auto &co:corridors){
            co[0]--,co[1]--;
            e[co[0]][co[1]]=1;
            e[co[1]][co[0]]=1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(e[i][j]&&e[j][i]){
                    auto c=e[i]&e[j];
                    ans+=c.count();
                }
            }
        }
        return ans/3;
    }
};
