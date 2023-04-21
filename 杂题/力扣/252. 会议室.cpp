/*
排序，如果前一个会议还未结束，下一个会议就已开始，则false
*/
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<intervals[i-1][1]) return false;
        }
        return true;
    }
};
