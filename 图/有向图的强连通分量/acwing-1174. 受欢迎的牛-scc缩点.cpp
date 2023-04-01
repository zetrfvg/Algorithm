/*
连通分量：该分量中任意两点均可相互到达
强连通分量：极大的连通分量

将整个图缩点转化为一个DAG
如果仅存在一个出度为0的scc，那么答案就是这个scc的大小
如果存在两个及两个以上出度为0的scc，那么说明没有任何一头牛被所有牛欢迎，答案为0
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	stack<int> st;
	vector<int> low(n),dfn(n),instk(n);
	vector<vector<int>> e(n);
	vector<int> scc(n),dout(n),siz(n);
	int cnt=0,time=0;
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
	int ans=0,k=0;
	for(int i=0;i<n;i++){
		for(auto j:e[i]){
			if(scc[i]!=scc[j]){
				dout[scc[i]]++;
			}
		}
	}
	for(int i=0;i<cnt;i++){
		if(!dout[i]){
			ans=siz[i];
			k++;
		}
	}
	if(k==1){
		cout<<ans<<'\n';
	}else{
		cout<<0<<'\n';
	}
  	return 0;
}
