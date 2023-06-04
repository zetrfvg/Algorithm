/*
扫描线+堆
每次有人入场，则从堆中取出编号最小的座位
每次有人离场，则把他的座位号放入堆中
*/
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        set<int> st;
        int n=times.size();
        for(int i=0;i<n;i++) st.insert(i);
        vector<vector<int>> event;
        vector<int> chair(n);
        for(int i=0;i<n;i++){
            event.push_back({times[i][0],1,i});
            event.push_back({times[i][1],-1,i});
        }
        sort(event.begin(),event.end());
        for(int i=0;i<2*n;i++){
            if(event[i][1]==1){
                chair[event[i][2]]=*st.begin();
                st.erase(st.begin());
                if(event[i][2]==targetFriend) return chair[targetFriend];
            }else{
                st.insert(chair[event[i][2]]);
            }
        }
        return -1;
    }
};
