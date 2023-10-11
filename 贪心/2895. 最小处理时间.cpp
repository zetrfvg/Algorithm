/*
processorTime升序排序，tasks降序排序
排序后，每个处理器依次处理四个任务取最大值即为答案
*/
class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int ans=0;
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.begin(),tasks.end(),greater<>());
        for(int i=0;i<tasks.size();i++){
            ans=max(ans,processorTime[i/4]+tasks[i]);
        }
        return ans;
    }
};
