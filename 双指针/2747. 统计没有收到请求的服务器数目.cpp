/*
离线+双指针
对logs按升序排序，对query也升序排列，方便离线来回答所有询问
对于询问query[r]，双指针把所有左端点在query[r]左边的加入区间，把所有右端点在query[r]-x左边的移除区间
*/
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& query) {
        int m=logs.size();
        int g[n+1];
        memset(g,0,sizeof g);
        int cnt=0;
        sort(logs.begin(),logs.end(),[](const auto &x,const auto &y){
            return x[1]<y[1];
        });
        int v=query.size();
        vector<int> ids(v);
        iota(ids.begin(),ids.end(),0);
        sort(ids.begin(),ids.end(),[&](const auto &x,const auto &y){
            return query[x]<query[y];
        });
        vector<int> ans(v);
        for(int u=0,l=0,r=0;r<v;r++){
            while(l<m&&logs[l][1]<query[ids[r]]-x) l++;
            while(u<=l&&u<m&&logs[u][1]<query[ids[r]]-x){
                if(g[logs[u][0]]==logs[u][1]) cnt--;
                u++;
            }
            while(l<m&&logs[l][1]<=query[ids[r]]){
                if(g[logs[l][0]]<query[ids[r]]-x) cnt++;
                g[logs[l][0]]=logs[l][1];
                l++;
            }
            ans[ids[r]]=n-cnt;
        }
        return ans;
    }
};
