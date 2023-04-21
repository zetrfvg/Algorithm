/*
对于一个intervals[i]，我们把他拆分成两个事件
在intervals[i][0]时开始一个会议，记为{intervals[i][0],1}
在intervals[i][1]时开始一个会议，记为{intervals[i][1],-1}
对所有事件按时间排序，然后扫描线即可
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int,int>> e;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            e.push_back({intervals[i][0],1});
            e.push_back({intervals[i][1],-1});
        }
        sort(e.begin(),e.end());
        int cnt=0,ans=0;
        for(auto &[a,b]:e){
            cnt+=b;
            ans=max(ans,cnt);
        }
        return ans;
    }
};
