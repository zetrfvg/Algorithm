/*
BFS搜索状态，每个可达的点有偶两个状态，向前到达该点，向后到达该点
其余模拟即可
*/
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> st(forbidden.begin(),forbidden.end());
        queue<tuple<int,int,int>> q;
        q.push({0,1,0});
        int sz=max(*max_element(forbidden.begin(), forbidden.end())+a,x)+b;
        unordered_set<int> vis;
        vis.insert(0);
        while(!q.empty()){
            auto [y,dir,dis]=q.front();
            q.pop();
            if(x==y) return dis;
            if(y+a<=sz&&!vis.count(y+a)&&!st.count(y+a)){
                q.push({y+a,1,dis+1});
                vis.insert(y+a);
            }
            if(dir==1&&y-b>=0&&!vis.count(-y+b)&&!st.count(y-b)){
                q.push({y-b,-1,dis+1});
                vis.insert(-y+b);
            }
        }
        return -1;
    }
};
