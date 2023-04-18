/*
哈希表+并查集
用一个哈希表来维护某个邮箱属于哪个集合，如果当前枚举到的邮箱在之前出现过，则合并这两个集合即可
合并完之后，把所有邮箱按对应的集合存储到一个set中，按序返回答案即可
*/
template<typename T>
struct DSU{
	int n;
	vector<T> p,siz;
	DSU(int _n):p(_n+1),siz(_n+1),n(_n){
		iota(p.begin(),p.end(),0);
		for(int i=0;i<=n;i++) siz[i]=1;
	}
	T findd(T x){
		return p[x]==x?x:p[x]=findd(p[x]);
	}
	void unionn(T x,T y){
		x=findd(x),y=findd(y);
		if(x==y) return;
        if(siz[x]>siz[y]) swap(x,y);
		p[x]=y;
		siz[y]+=siz[x];
	}
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int> mp;
        vector<set<string>> g(n);
        DSU<int> dsu(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.count(accounts[i][j])) dsu.unionn(i,mp[accounts[i][j]]);
                else mp[accounts[i][j]]=i;
            }
        }
        for(auto &[s,i]:mp){
            g[dsu.findd(i)].insert(s);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(dsu.p[i]==i){
                vector<string> t{accounts[i][0]};
                for(auto &s:g[i]){
                    t.push_back(s);
                }
                ans.push_back(t);
            }
        }
        return ans;
    }
};
