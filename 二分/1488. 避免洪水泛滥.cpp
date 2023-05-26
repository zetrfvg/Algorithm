/*
哈希表＋set+二分+贪心
用一个哈希表来记录每个湖泊上次下雨是什么时候，set来记录之前出现过的晴天
枚举下雨的日子，如果湖泊x要发生洪水，则在哈希表中找到它上一次下雨的日子
在set中二分找到这个日子之后的最近的一个晴天，在这天把x的水抽走
基于贪心的思想，我们二分找最近的这个位置，可以给后面的抽水提供更大的选择区间
*/
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        set<int> st;
        unordered_map<int,int> g;
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            if(!rains[i]){
                st.insert(i);
            }else{
                if(g.count(rains[i])){
                    auto p=st.upper_bound(g[rains[i]]);
                    if(p==st.end()){
                        return {};
                    }
                    ans[*p]=rains[i];
                    st.erase(p);
                }
                g[rains[i]]=i;
            }
        }
        for(auto i:st) ans[i]=1;
        return ans;
    }
};
