/*
求连通块数量cnt
对于整个图，枚举每个连通块
对于枚举的连通块，再枚举其块内的各个割点
对于每个割点，删去它后，会分成若干个个连通块；对能分成的连通块数量取最大值ans即可
答案则为ans+cnt-1
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	while(cin>>n>>m,n||m){
		vector<int> low(n),dfn(n);
		vector<int> h(n,-1),e(m*2),ne(m*2);
		int cnt=0,idx=0,time=0,ans=0;
		auto add=[&](int a,int b){
			e[idx]=b,ne[idx]=h[a],h[a]=idx++;
		};
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			add(a,b);
			add(b,a);	
		}
		int root;
		function<void(int)> tarjan=[&](int x){
			dfn[x]=low[x]=++time;
			int cnt=0;
			for(int i=h[x];~i;i=ne[i]){
				int y=e[i];
				if(!dfn[y]){
					tarjan(y);
					low[x]=min(low[x],low[y]);
					if(low[y]>=dfn[x]) cnt++;
				}else low[x]=min(low[x],dfn[y]);
			}
			if(x!=root&&cnt) cnt++;
			ans=max(ans,cnt);
		};
		for(root=0;root<n;root++){
			if(!dfn[root]){
				cnt++;
				tarjan(root);
			}
		}
		cout<<ans+cnt-1<<'\n';
	}
  	return 0;
}
