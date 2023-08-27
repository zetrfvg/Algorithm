/*
将newInterval插入到intervals，并对intervals排序
之后就是56.合并区间这题
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        auto t=intervals[0];
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(t[1]<intervals[i][0]){
                ans.push_back(t);
                t=intervals[i];
            }else t[1]=max(t[1],intervals[i][1]);
        }
        ans.push_back(t);
        return ans;
    }
};
