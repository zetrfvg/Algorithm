/*
用三个列表来存储三种颜色的下标
对于一个询问，我们在询问的颜色对应的列表中使用二分查找
找到第一个大于等于它的下标和第一个小于它的下标，二者取最近值即可
需要注意判断无解的情况
*/
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>> g(3);
        int n=colors.size();
        for(int i=0;i<n;i++){
            g[colors[i]-1].push_back(i);
        }
        vector<int> ans;
        for(auto q:queries){
            int i=q[0],c=q[1]-1;
            if(!g[c].size()) ans.push_back(-1);
            else{
                int res=1e9;
                auto p=lower_bound(g[c].begin(),g[c].end(),i);
                if(p!=g[c].end()) res=min(res,*p-i);
                if(p!=g[c].begin()) res=min(res,i-*(--p));
                ans.push_back(res);
            }
        }
        return ans;
    }
};
