/*
按区间右端点排序
基于贪心，我们希望一箭可以尽可能射掉更多的气球
所以每次射出箭，我们选择在区间的右端点出射出
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const auto &a,const auto &b){
            return a[1]<b[1];
        });
        int n=points.size();
        int ans=1,R=points[0][1];
        for(int i=1;i<n;i++){
            if(R<points[i][0]){
                ans++;
                R=points[i][1];
            }
        }
        return ans;
    }
};
