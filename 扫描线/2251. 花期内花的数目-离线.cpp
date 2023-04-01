/*
一朵花的花期为[start,end]，则把他划分为两个事件：在start时加一朵花；在end+1时减一朵花
将所有询问按从小到大排序，对于某个人第t时刻到达，则执行t时刻之前的所有事件，用前缀和的思想统计当前多少朵花
*/
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=flowers.size(),m=people.size();
        vector<pair<int,int>> event,q(m);
        vector<int> ans(m);
        for(int i=0;i<n;i++){
            event.push_back({flowers[i][0],1});
            event.push_back({flowers[i][1]+1,-1});
        }
        sort(event.begin(),event.end());
        for(int i=0;i<m;i++){
            q[i]={people[i],i};
        }
        sort(q.begin(),q.end());
        int now=0;
        for(int i=0,j=0;j<m;j++){
            while(i<n*2&&event[i].first<=q[j].first){
                now+=event[i++].second;
            }
            ans[q[j].second]=now;
        }
        return ans;
    }
};
