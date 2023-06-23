/*
暴力枚举数据范围的所有点
*/
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto &u:queries){
            int x=u[0],y=u[1],r=u[2];
            int cnt=0;
            for(auto &p:points){
                int xx=x-p[0],yy=y-p[1];
                if(xx*xx+yy*yy<=r*r) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
