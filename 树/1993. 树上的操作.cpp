/*
模拟即可
*/
class LockingTree {
public:
    vector<vector<int>> e;
    vector<int> st,fa;
    int n;
    LockingTree(vector<int>& parent) {
        n=parent.size();
        e.resize(n);
        st.resize(n);
        fa.resize(n);
        for(int i=1;i<n;i++){
            e[parent[i]].push_back(i);
            fa[i]=parent[i];
        }
        fa[0]=-1;
    }
    
    bool lock(int num, int user) {
        if(st[num]) return false;
        st[num]=user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(!st[num]||st[num]!=user) return false;
        st[num]=0;
        return true;
    }
    
    bool upgrade(int num, int user) {
        int pos=num;
        while(pos!=-1&&!st[pos]) pos=fa[pos];
        if(pos!=-1) return false;
        function<bool(int)> dfs=[&](int x){
            bool res=st[x]>0;
            st[x]=0;
            for(auto y:e[x]){
                res|=dfs(y);
            }
            return res;
        };
        if(!dfs(num)) return false;
        st[num]=user;
        return true;
    }
};
