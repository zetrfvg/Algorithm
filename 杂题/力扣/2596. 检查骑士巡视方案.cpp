/*
用数组e将骑士走过的格点按时间先后排序
判断走的每一步是否合法即可
*/
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& g) {
        if(g[0][0]!=0) return false;
        int n=g.size();
        vector<vector<int>> e;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                e.push_back({g[i][j],i,j});
            }
        }
        sort(e.begin(),e.end());
        for(int i=1;i<e.size();i++){
            int x1=e[i][1],y1=e[i][2];
            int x2=e[i-1][1],y2=e[i-1][2];
            int a=max(abs(x1-x2),abs(y1-y2));
            int b=min(abs(x1-x2),abs(y1-y2));
            if(a!=2||b!=1) return false;
        }
        return true;
    }
};
