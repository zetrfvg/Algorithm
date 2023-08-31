/*
二分+单调队列
check：当前二分的答案为mid，那么肯定选能力值最高的mid个工人来完成难度值最低的mid个任务，所以首先排序
首先考虑，对于两个能力值不同工人来完成两个难度不同的任务，这里优先让能力值高的完成难度高的任务
因为如果能力值高的人完不成这个任务，能力值低的也完不成，如果二者都可以完成这个任务，那么能力值低的也可以完成另一个难度低的任务
从难度高到底枚举任务tasks[i]，用一个单调队列来维护能够完成这个任务的工人
把吃药之后能够完成tasks[i]的工人从队首插入，以保证队列的单调性
入队完毕之后，考虑不吃药的情况，那么从队列中选取能力值最高的来完成，即队尾的工人
如果队尾的需要吃药来完成，基于贪心，有能力值更低的工人吃药也能完成，那么选这个能力值最低的，即队首的工人(前提是药未被消耗完)
如此可以check函数可以做到O(mid)
时间复杂度:O(nlogn+mlogm)
*/
class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int n=tasks.size(),m=workers.size();
        auto check=[&](int mid){
            int cnt=pills;
            deque<int> q;
            int j=m-1;
            for(int i=mid-1;~i;i--){
                while(j>=m-mid&&workers[j]+strength>=tasks[i]){
                    q.push_front(workers[j--]);
                }
                if(q.empty()) return false;
                if(q.back()>=tasks[i]){
                    q.pop_back();
                }else{
                    if(!cnt) return false;
                    cnt--;
                    q.pop_front();
                }
            }
            return true;
        };
        int l=0,r=min(m,n);
        while(l<r){
            int mid=(l+r+1)>>1;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        return l;
    }
};
