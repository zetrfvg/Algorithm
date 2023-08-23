/*
求点双连通分量
割点上必须放置1个出口
考虑缩点后的每个连通分量
如果连通分量中的点数大于1且不包含割点，则需要放2个出口
如果连通分量中的点数等于1且不包含割点，则需要放1个出口
如果连通分量中只包含一个割点，则需要放1个出口
以上能保证放置的出口数量最少
方案数由乘法原理来求
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N=1010;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	int T=1;
	while(cin>>m,m){
		n=0;
		stack<int> st;
		vector<int> low(N),dfn(N);
		vector<int> h(N,-1),e(m*2),ne(m*2);
		vector<int> cut(N),dcc[N];
		int dcc_cnt=0,idx=0,time=0;
		auto add=[&](int a,int b){
			e[idx]=b,ne[idx]=h[a],h[a]=idx++;
		};
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			n=max({n,a,b});
			a--,b--;
			add(a,b);
			add(b,a);	
		}
		int root;
		function<void(int)> tarjan=[&](int x){
			dfn[x]=low[x]=++time;
			st.push(x);
			if(x==root&&h[x]==-1){
				dcc[dcc_cnt++].push_back(x);
				st.pop();
				return;
			}
			int cnt=0;
			for(int i=h[x];~i;i=ne[i]){
				int y=e[i];
				if(!dfn[y]){
					tarjan(y);
					low[x]=min(low[x],low[y]);
					if(dfn[x]<=low[y]){
						cnt++;
						if(x!=root||cnt>1) cut[x]=1;
						int z=-1;
						while(z!=y){
							z=st.top();
							st.pop();
							dcc[dcc_cnt].push_back(z);
						}
						dcc[dcc_cnt++].push_back(x);
					}
				}else low[x]=min(low[x],dfn[y]);
			}
		};
		for(root=0;root<n;root++){
			if(!dfn[root]){
				tarjan(root);
			}
		}
		int res=0;
		ull ans=1;
		for(int i=0;i<dcc_cnt;i++){
			int cnt=0;
			for(int j=0;j<dcc[i].size();j++){
				if(cut[dcc[i][j]]){
					cnt++;	
				}
			}
			if(!cnt){
				if(dcc[i].size()>1){
					res+=2;
					ans*=dcc[i].size()*(dcc[i].size()-1)/2;
				}else{
					res++;
				}
			}else if(cnt==1){
				res++;
				ans*=dcc[i].size()-1;	
			}
		}
		printf("Case %d: %d %llu\n",T++,res,ans);
	}
  	return 0;
}
