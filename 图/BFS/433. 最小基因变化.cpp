/*
建图+BFS找最短路
*/
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene==endGene) return 0;
        bank.push_back(startGene);
        int n=bank.size();
        vector<vector<int>> e(n);
        vector<int> vis(n);
        int end=-1;
        for(int i=0;i<n;i++) if(bank[i]==endGene) end=i;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int c=0;
                for(int k=0;k<8;k++){
                    c+=bank[i][k]!=bank[j][k];
                }
                if(c==1){
                    e[i].push_back(j);
                    e[j].push_back(i);
                }
            }
        }
        queue<int> q;
        q.push(n-1);
        vis[n-1]=1;
        int h=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int x=q.front();
                q.pop();
                if(x==end) return h;
                for(auto y:e[x]){
                    if(vis[y]) continue;
                    vis[y]=1;
                    q.push(y);
                }
            }
            h++;
        }
        return -1;
    }
};
