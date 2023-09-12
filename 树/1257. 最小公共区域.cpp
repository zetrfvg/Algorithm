/*
建树后dfs找到两个region1和region2都在的最小的子树结点即可
*/
class Solution {
public:
    static const int N=1e4+10;
    vector<int> e[N];
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        int idx=0;
        unordered_map<string,int> p;
        vector<int> deg(1e4+10);
        for(auto s:regions){
            for(int i=0;i<s.size();i++){
                if(!p.count(s[i])) p[s[i]]=++idx;
                if(i){
                    e[p[s[0]]].push_back(p[s[i]]);
                    deg[p[s[i]]]=1;
                }
            }
        }
        int root,ans=-1;
        vector<int> cnt(idx+1);
        cnt[p[region1]]++,cnt[p[region2]]++;
        for(int i=1;i<=idx;i++) if(!deg[i]) root=i;
        function<void(int)> dfs=[&](int x){
            for(auto y:e[x]){
                dfs(y);
                cnt[x]+=cnt[y];
            }
            if(cnt[x]==2&&ans==-1) ans=x;
        };
        dfs(root);
        for(auto &[a,b]:p) if(ans==b) return a;
        return "";
    }
};
