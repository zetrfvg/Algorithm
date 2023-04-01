/*
首先缩点，将图转化为DAG
1、现在请问最少需要将一个新软件直接提供给多少个学校，才能使软件能够通过网络被传送到所有学校？
入度为0的scc数量即为答案
2、最少需要添加几条新的支援关系，使得将一个新软件提供给任何一个学校，其他所有学校就都可以通过网络获得该软件？
分两种情况：
Ⅰ：x是一个入度为0的scc，把其他所有入度为0的scc向x连一条边，y是一个出度为0的scc，且x可以走到y，再从y向x连一条边。总共添加的边数为入度为0的scc的数量，记为a
Ⅱ：y是一个出度为0的scc，出度为0的scc组成一个序列[y,y2,y3,……,yn]，按y->y2，y2->y3如此依次连边
    x是一个入度为0的scc，且x可以走到y，再从yn向x连一条边。总共添加的边数为出度为0的scc的数量，记为b
答案即为max(a,b)
注：要特判scc数量为1的情况
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n;
	stack<int> st;
	vector<int> low(n),dfn(n),instk(n);
	vector<vector<int>> e(n);
	vector<int> scc(n),dout(n),siz(n),din(n);
	int cnt=0,time=0;
	for(int i=0;i<n;i++){
		int j;
		while(1){
			cin>>j;
			if(!j) break;
			e[i].push_back(j-1);
		}
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
				din[scc[j]]++;
			}
		}
	}
	int a=0,b=0;
	for(int i=0;i<cnt;i++){
		if(!din[i]) a++;
		if(!dout[i]) b++;
	}
	if(cnt==1){
		cout<<1<<'\n';
		cout<<0<<'\n';
	}else{
		cout<<a<<'\n';
		cout<<max(a,b)<<'\n';
	}
  	return 0;
}
