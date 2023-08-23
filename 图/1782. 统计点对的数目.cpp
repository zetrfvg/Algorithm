/*
预处理出每个元素的度数，再拷贝一份度数数组对新数组排序
对于每个询问，首先用双指针枚举右端点求出可能满足要求的点对数量
双指针：对于一组l,r，如果sorted_deg[l]+sorted_deg[r]<=q，说明不够此时左移左指针直到sorted_deg[l]+sorted_deg[r]>q，此时能够与r相匹配的点有r-l个，累计该次询问的答案
去重，重复贡献主要看一对点对之间的是否存在边，这里枚举边，对于一对点对，如果其度数之和减去它们之间的边数小于q，则说明该点对不合法需要取出，具体实现如下
*/
class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> deg(n+1);
        unordered_map<int,int> cnt;
        for(auto &e:edges){
            if(e[0]>e[1]) swap(e[0],e[1]);
            deg[e[0]]++,deg[e[1]]++;
            cnt[(e[0]<<15)|e[1]]++;//用一个int来存储两个不超过32768的数，表示该两点之间存在一条边
        }
        vector<int> ans(queries.size());
        auto sorted_deg=deg;
        sort(sorted_deg.begin(),sorted_deg.end());
        for(int i=0;i<queries.size();i++){
            int l=1,r=n;
            while(l<r){
                if(sorted_deg[l]+sorted_deg[r]<=queries[i]) l++;
                else ans[i]+=r-l,r--;
            }
            for(auto &[a,b]:cnt){
                int x=(a>>15),y=a^(x<<15);
                int tot=deg[x]+deg[y];
                if(tot>queries[i]&&tot-b<=queries[i]) ans[i]--;
            }
        }
        return ans;
    }
};
