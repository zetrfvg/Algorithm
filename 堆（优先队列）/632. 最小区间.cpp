/*
依次从小到大枚举n个列表中的元素
用一个堆来维护这些元素，每次从这些元素中选择最小的元素
把它所在相应的列表的后继元素放入堆中，同时用这个后继元素来更新新的n个元素中的最大值
因为后继元素替代了它，因此把它弹走，此时堆顶的元素就是这n个元素中最小的
用最大元素减去最小元素来更新答案区间即可
*/
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        int mx=-1e9,mn=1e9;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q;
        for(int i=0;i<n;i++){
            q.push({nums[i][0],i,0});
            mx=max(mx,nums[i][0]);
            mn=min(mn,nums[i][0]);
        }
        int L=mx-mn;
        vector<int> ans{mn,mx};
        while(!q.empty()){
            auto [x,i,j]=q.top();
            q.pop();
            if(j==nums[i].size()-1) continue;
            q.push({nums[i][j+1],i,j+1});
            mx=max(mx,nums[i][j+1]);
            if(q.size()==n) mn=get<0>(q.top());
            if(mx-mn<L) ans[0]=mn,ans[1]=mx,L=mx-mn;
        }
        return ans;
    }
};
