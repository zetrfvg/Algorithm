/*
求出所有怪物到达城市的时间
我们尽可能在每个怪物到达城市之前的最晚时间消灭
按从小到大排序，依次判断即可
*/
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int> time(n);
        for(int i=0;i<n;i++){
            time[i]=(dist[i]+speed[i]-1)/speed[i];
        }
        sort(time.begin(),time.end());
        for(int i=0;i<n;i++){
            if(time[i]<i+1) return i;
        }
        return n;
    }
};
