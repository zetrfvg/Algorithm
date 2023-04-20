/*
并查集合并
用集合中最小的字符来代表这个集合，对basestr进行替换即可
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
		if(y>x) swap(x,y);
		p[x]=y;
		siz[y]+=siz[x];
	}
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU<int> dsu(26);
        int n=s1.size();
        for(int i=0;i<n;i++){
            dsu.unionn(s1[i]-'a',s2[i]-'a');
        }
        for(auto &c:baseStr){
            c=(char)'a'+dsu.findd(c-'a');
        }
        return  baseStr;
    }
};
