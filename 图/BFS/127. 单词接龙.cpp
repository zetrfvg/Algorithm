/*
建图+BFS找最短路
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n=wordList.size();
        int begin=n-1,end=-1;
        vector<vector<int>> e(n);
        for(int i=0;i<n;i++){
            if(wordList[i]==endWord) end=i;
            for(int j=i+1;j<n;j++){
                int cnt=0;
                for(int k=0;k<wordList[i].size();k++){
                    cnt+=wordList[i][k]!=wordList[j][k];
                }
                if(cnt==1){
                    e[i].push_back(j);
                    e[j].push_back(i);
                } 
            }
        }
        if(end==-1) return 0;
        queue<int> q;
        q.push(begin);
        int h=1;
        vector<int> vis(n);
        vis[begin]=1;
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
        return 0;
    }
};
