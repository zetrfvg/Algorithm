/*
对区间排序，对询问按升序处理，用一个小根堆来维护合法的区间集合
双指针枚举，如果下一个区间左端点在询问的左边，则加入堆
如果堆顶区间的右端点在询问的左边，则从堆中移除
此时堆顶的元素就是对应询问的最小区间长度
*/
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n=intervals.size(),m=queries.size();
        vector<int> ids(m),ans(m,-1);
        iota(ids.begin(),ids.end(),0);
        sort(intervals.begin(),intervals.end(),[](const auto &a,const auto &b){
            return a[0]<b[0];
        });
        sort(ids.begin(),ids.end(),[&](int &i,int &j){
            return queries[i]<queries[j];
        });
        priority_queue<pair<int,int>> q;
        for(int i=0,j=0;i<m;i++){
            while(j<n&&intervals[j][0]<=queries[ids[i]]){
                q.push({intervals[j][0]-intervals[j][1]-1,j});
                j++;
            }
            while(!q.empty()){
                auto &[dis,p]=q.top();
                if(intervals[p][1]<queries[ids[i]]) q.pop();
                else break;
            }
            if(!q.empty()) ans[ids[i]]=-q.top().first;
        }
        return ans;
    }
};
