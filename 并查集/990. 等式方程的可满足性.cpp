/*
先按相等的式子合并集合
然后判断不等的式子两边元素是否属于同一集合
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
    bool equationsPossible(vector<string>& equations) {
        DSU<int> dsu(26);
        for(auto &s:equations){
            if(s[1]=='='){
                dsu.unionn(s[0]-'a',s[3]-'a');
            }
        }
        for(auto &s:equations){
            if(s[1]=='!'){
                if(dsu.findd(s[0]-'a')==dsu.findd(s[3]-'a')){
                    return false;
                }
            }
        }
        return true;
    }
};
