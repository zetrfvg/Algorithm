/*
暴搜+模拟
*/
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int ans=0;
        vector<int> vis(10),g;
        function<void()> dfs=[&](){
            if(g.size()>=m&&g.size()<=n){
                ans++;
            }
            if(g.size()>=n) return;
            for(int i=1;i<=9;i++){
                if(vis[i]){
                    continue;
                }else if(i==1){
                    if(g.size()&&g.back()==3&&!vis[2]) continue;
                    if(g.size()&&g.back()==9&&!vis[5]) continue;
                    if(g.size()&&g.back()==7&&!vis[4]) continue;
                }else if(i==2){
                    if(g.size()&&g.back()==8&&!vis[5]) continue;
                }else if(i==3){
                    if(g.size()&&g.back()==1&&!vis[2]) continue;
                    if(g.size()&&g.back()==7&&!vis[5]) continue;
                    if(g.size()&&g.back()==9&&!vis[6]) continue;
                }else if(i==4){
                    if(g.size()&&g.back()==6&&!vis[5]) continue;
                }else if(i==6){
                    if(g.size()&&g.back()==4&&!vis[5]) continue;
                }else if(i==7){
                    if(g.size()&&g.back()==1&&!vis[4]) continue;
                    if(g.size()&&g.back()==3&&!vis[5]) continue;
                    if(g.size()&&g.back()==9&&!vis[8]) continue;
                }else if(i==8){
                    if(g.size()&&g.back()==2&&!vis[5]) continue;
                }else if(i==9){
                    if(g.size()&&g.back()==1&&!vis[5]) continue;
                    if(g.size()&&g.back()==3&&!vis[6]) continue;
                    if(g.size()&&g.back()==7&&!vis[8]) continue;
                }
                vis[i]=1;
                g.push_back(i);
                dfs();
                vis[i]=0;
                g.pop_back();
            }
        };
        dfs();
        return ans;
    }
};
