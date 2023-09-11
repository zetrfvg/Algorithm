/*
离线+双指针
两个数组按size降序排序
枚举询问，把size不小于当前询问的房间id用一个set维护，在set中可以二分找到离询问的preferred最近的两个元素，取距离最小的一个id即可
*/
class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        set<int> st;
        sort(rooms.begin(),rooms.end(),[](const auto &a,const auto &b){
            return a[1]>b[1];
        });
        int k=queries.size();
        vector<int> ids(k),ans(k,1e9);
        iota(ids.begin(),ids.end(),0);
        sort(ids.begin(),ids.end(),[&](const auto &i,const auto &j){
            return queries[i][1]>queries[j][1];
        });
        for(int i=0,j=0;i<k;i++){
            while(j<rooms.size()&&rooms[j][1]>=queries[ids[i]][1]){
                st.insert(rooms[j][0]);
                j++;
            }
            if(st.size()){
                int id=queries[ids[i]][0];
                auto p=st.lower_bound(id);
                if(p!=st.end()) ans[ids[i]]=*p;
                if(p!=st.begin()){
                    p--;
                    if(id-*p<=ans[ids[i]]-id) ans[ids[i]]=*p;
                }
            }else{
                ans[ids[i]]=-1;
            }
        }
        return ans;
    }
};
