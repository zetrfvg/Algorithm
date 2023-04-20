/*
按题意模拟合并集合，最后统计集合数量即可
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
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size(),m=strs[0].size();
        DSU<int> dsu(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int l=-1,r=-1,c=0;
                for(int k=0;k<m;k++){
                    if(strs[i][k]!=strs[j][k]){
                        c++;
                        if(l==-1) l=k;
                        else r=k;
                    }
                }
                if(c==0||(c==2&&strs[i][l]==strs[j][r]&&strs[i][r]==strs[j][l])){
                    dsu.unionn(i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dsu.p[i]==i) ans++;
        }
        return ans;
    }
};
