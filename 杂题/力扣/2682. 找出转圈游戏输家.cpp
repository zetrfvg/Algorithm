/*
模拟
*/
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> ans,vis(n);
        vis[0]=1;
        for(int i=1,p=0;;i++){
            p=(p+k*i)%n;
            if(vis[p]) break;
            vis[p]++;
        }
        for(int i=0;i<n;i++) if(!vis[i]) ans.push_back(i+1);
        return ans;
    }
};
