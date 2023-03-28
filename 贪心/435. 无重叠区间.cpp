/*
尽可能地选择靠左边的区间，并维护一个最远的右端点
如果下一个区间冲突，则删去
否则，保留区间，更新右端点
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto &a,const auto &b){
            return a[1]<b[1];
        });
        int n=intervals.size();
        int ans=1,R=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=R){
                ans++;
                R=intervals[i][1];
            }
        }
        return n-ans;
    }
};
