/*
边双连通分量(edcc)：不含割边的极大连通分量

缩点之后，找度为1的叶子节点，只需要把叶子节点两两组合连边即为答案
叶子节点的数量为cnt_leaf，则答案为(cnt_leaf+1)/2，向上取整
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	stack<int> st;
	vector<int> low(n),dfn(n);
	vector<int> h(n,-1),e(m*2),ne(m*2);
	vector<int> is_bridge(m*2);
	vector<int> dcc(n),d(n);
	int cnt=0,idx=0,time=0;
	auto add=[&](int a,int b){
		e[idx]=b,ne[idx]=h[a],h[a]=idx++;
	};
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		add(a,b);
		add(b,a);	
	}
	function<void(int,int)> tarjan=[&](int x,int from){
		dfn[x]=low[x]=++time;
		st.push(x);
		for(int i=h[x];~i;i=ne[i]){
			int y=e[i];
			if(!dfn[y]){
				tarjan(y,i);
				low[x]=min(low[x],low[y]);
				if(low[y]>dfn[x]){
					is_bridge[i]=is_bridge[i^1]=1;
				}
			}else if(i!=(from^1)){
				low[x]=min(low[x],dfn[y]);
			}
		}
		if(dfn[x]==low[x]){
			int y=-1;
			while(y!=x){
				y=st.top();
				st.pop();
				dcc[y]=cnt;
			}
			++cnt;
		}
	};
	tarjan(0,-1);
	for(int i=0;i<idx;i++){
		if(is_bridge[i]){
			d[dcc[e[i]]]++;
		}
	}
	int cnt_leaf=0;
	for(int i=0;i<cnt;i++){
		if(d[i]==1) cnt_leaf++;
	}
	cout<<(cnt_leaf+1)/2<<'\n';
  	return 0;
}
