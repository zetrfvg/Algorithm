/*
模拟即可
*/
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& gird) {
        int ans=0;
        int n=gird.size(),m=gird[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int k=0;k<m;k++){
            int t=0,id;
            for(int i=0;i<n;i++){
                int v=0;
                for(int j=0;j<m;j++){
                    if(!vis[i][j]&&gird[i][j]>v){
                        v=gird[i][j];
                        id=j;
                    }
                }
                t=max(v,t);
                vis[i][id]=1;
            }
            ans+=t;
        }
        return ans;
    }
};
