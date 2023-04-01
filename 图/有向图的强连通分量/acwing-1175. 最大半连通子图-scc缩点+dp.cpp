/*
对整个图缩点建立一个新的DAG
那么最大半连通子图就是这个DAG上最长的一条链上结点的个数
因为tarjan缩点之后，scc数组的逆序就是新图的一个拓扑序，所以直接在新图上对scc逆序递推最长链的方案数有多少个即可
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,mod;
	cin>>n>>m>>mod;
	stack<int> st;
	vector<int> dfn(n),low(n),instk(n);
	vector<vector<int>> e(n),ne(n);
	vector<int> scc(n),siz(n);
	vector<int> mx(n),tot(n);
	unordered_set<ll> S;
	int cnt,time;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--,y--;
		e[x].push_back(y);
	}
	function<void(int)> tarjan=[&](int x){
		dfn[x]=low[x]=++time;
		st.push(x),instk[x]=1;
		for(auto y:e[x]){
			if(!dfn[y]){
				tarjan(y);
				low[x]=min(low[x],low[y]);
			}else if(instk[y]){
				low[x]=min(low[x],dfn[y]);
			}
		}
		if(dfn[x]==low[x]){
			int y=-1;
			while(y!=x){
				y=st.top();
				st.pop();
				instk[y]=0;
				scc[y]=cnt;
				++siz[cnt];
			}
			++cnt;
		}
	};
	for(int i=0;i<n;i++) if(!dfn[i]) tarjan(i);
	for(int i=0;i<n;i++){
		for(auto j:e[i]){
			int x=scc[i],y=scc[j];
			ll edge=1LL*x*1000000+y;
			if(x!=y&&!S.count(edge)){
				ne[x].push_back(y);
				S.insert(edge);
			}
		}
	}
	for(int i=cnt-1;~i;i--){
		if(!tot[i]){
			mx[i]=siz[i];
			tot[i]=1;
		}
		for(auto j:ne[i]){
			if(mx[j]<mx[i]+siz[j]){
				mx[j]=mx[i]+siz[j];
				tot[j]=tot[i];
			}else if(mx[j]==mx[i]+siz[j]){
				tot[j]=(tot[j]+tot[i])%mod;
			}
		}
	}
	int mx_cnt=0,ans=0;
	for(int i=0;i<cnt;i++){
		if(mx[i]>mx_cnt){
			mx_cnt=mx[i];
			ans=tot[i];
		}else if(mx[i]==mx_cnt){
			ans=(ans+tot[i])%mod;
		}
	}
	cout<<mx_cnt<<'\n';
	cout<<ans<<'\n';
  	return 0;
}a
