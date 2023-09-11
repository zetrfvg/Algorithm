/*
基于贪心，优先上结课时间早的课程，可以按截止日期枚举课程
枚举到课程i：
如果之前上的若干个课的总用时加上duration[i]不超过课程i的截止日期，则表示上完i是可行的
如果之前上的若干个课的总用时加上duration[i]大于课程i的截止日期，考虑之前上过课的最长的一个duration[j]，分两种情况：
①如果duration[j]>duration[i]，同样是上一个课程，i的用时更少，能节省出更多的时间给后面的课程，因此取消上课程j，改上课程i
②如果duration[j]<=duration[i]，那么上课程i会用更多的时间，因此不上i
基于此，需要一个从上过的课程中选取duration最大的一个数据结构来完成这个反悔贪心
*/
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        priority_queue<int> q;
        sort(courses.begin(),courses.end(),[](const auto &a,const auto &b){
            return a[1]<b[1];
        });
        int cnt=0;
        for(int i=0;i<n;i++){
            int duration=courses[i][0],lastday=courses[i][1];
            if(cnt+duration<=lastday){
                cnt+=duration;
                q.push(duration);
            }else if(!q.empty()&&duration<q.top()){
                cnt-=q.top()-duration;
                q.pop();
                q.push(duration);
            }
        }
        return q.size();
    }
};
