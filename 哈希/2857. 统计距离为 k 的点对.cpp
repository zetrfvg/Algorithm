/*
枚举坐标(x,y)
把拆分k为j和k-j两部分，j从0开始枚举，在哈希表中查询坐标(x^j,y^(k-j))的个数，累加答案即可
*/
class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        map<pair<int,int>,int> p;
        int n=coordinates.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            int x=coordinates[i][0],y=coordinates[i][1];
            for(int j=0;j<=k;j++){
                if(p.count({x^j,y^(k-j)})) ans+=p[{x^j,y^(k-j)}];
            }
            p[{x,y}]++;
        }
        return ans;
    }
};
