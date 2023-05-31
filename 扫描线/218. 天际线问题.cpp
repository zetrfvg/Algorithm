/*
扫描线+优先队列
用一个堆来维护当前建筑群的最大高度
将第i个建筑[left,right,height]划分为两个事件
一个是[left,height,1,i]表示扫描到这个事件时，向堆中加入第i个建筑的事件
一个是[right,height,-1,i]表示扫描到这个事件时，从堆中删除第i个建筑的事件
我们按横坐标对所有事件排序，从左到右依次处理，用h来表示当前这一系列事件之前的所有事件的处理之后建筑中的最大高度
因为会存在下标相同的事件，因此每次枚举的一系列横坐标相同的事件来处理
因为priority_queue不支持删除操作，这里用一个vis数组来标记某个建筑是否已经移除，这是延迟删除的技巧
处理完这些事件后，如果堆顶元素的高度和h不相等，则说明要向答案中加入这个轮廓的坐标(x,y)，x为当前处理的事件的横坐标，y为堆顶元素的纵坐标
更新答案之后再更新h即可
*/
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n=buildings.size();
        vector<vector<int>> event;
        for(int i=0;i<n;i++){
            event.push_back({buildings[i][0],buildings[i][2],1,i});
            event.push_back({buildings[i][1],buildings[i][2],-1,i});
        }
        sort(event.begin(),event.end());
        priority_queue<pair<int,int>> q;
        vector<int> vis(n);
        vector<vector<int>> ans;
        q.push({0,-1});
        int h=0;
        for(int i=0;i<n*2;){
            int j=i;
            while(j<n*2&&event[j][0]==event[i][0]){
                if(event[j][2]==-1) vis[event[j][3]]=1;
                else q.push({event[j][1],event[j][3]});
                j++;
            }
            while(!q.empty()){
                auto [y,k]=q.top();
                if(k==-1||!vis[k]) break;
                q.pop();
            }
            if(get<0>(q.top())!=h){
                ans.push_back({event[i][0],get<0>(q.top())});
            }
            h=get<0>(q.top());
            i=j;
        }
        return ans;
    }
};
