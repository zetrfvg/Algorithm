/*
按题意模拟
*/
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& q) {
        vector<int> g(n);
        int s=0;
        int m=q.size();
        vector<int> ans;
        for(int i=0;i<m;i++){
            int j=q[i][0],c=q[i][1];
            if(c!=g[j]){
                if(j&&g[j]&&g[j]==g[j-1]) s--;
                if(j<n-1&&g[j]&&g[j]==g[j+1]) s--;
                g[j]=c;
                if(j&&g[j]&&g[j]==g[j-1]) s++;
                if(j<n-1&&g[j]&&g[j]==g[j+1]) s++;
            }
            ans.push_back(s);
        }
        return ans;
    }
};
